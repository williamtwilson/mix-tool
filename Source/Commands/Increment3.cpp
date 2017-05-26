#include "Increment3.hpp"
#include <iostream>

Increment3::Increment3(): Command("INC3", 51) {}

void Increment3::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    long sum = machine.rI3.contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine.overflowToggle = Overflow::on;
	Word newR3Value = Word(sum % fifthPower);
        machine.rI3.load(newR3Value);
    } else {
	Word newR3Value = Word(sum);
        machine.rI3.load(newR3Value);
    }
    machine.incrementCycles(1);
    machine.incrementCommandPointer();
}

