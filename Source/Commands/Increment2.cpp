#include "Increment2.hpp"
#include <iostream>

Increment2::Increment2(): Command("INC2", 50) {}

void Increment2::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    long sum = machine.rI2.contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine.overflowToggle = Overflow::on;
	Word newR2Value = Word(sum % fifthPower);
        machine.rI2.load(newR2Value);
    } else {
	Word newR2Value = Word(sum);
        machine.rI2.load(newR2Value);
    }
    machine.incrementCycles(1);
    machine.incrementCommandPointer();
}

