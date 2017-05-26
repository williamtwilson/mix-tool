#include "Increment1.hpp"
#include <iostream>

Increment1::Increment1(): Command("INC1", 49) {}

void Increment1::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    long sum = machine.rI1.contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine.overflowToggle = Overflow::on;
	Word newR1Value = Word(sum % fifthPower);
        machine.rI1.load(newR1Value);
    } else {
	Word newR1Value = Word(sum);
        machine.rI1.load(newR1Value);
    }
    machine.incrementCycles(1);
    machine.incrementCommandPointer();
}

