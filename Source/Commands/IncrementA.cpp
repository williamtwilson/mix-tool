#include "IncrementA.hpp"
#include <iostream>

IncrementA::IncrementA(): Command("INCA", 48) {}

void IncrementA::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    long sum = machine.rA.contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine.overflowToggle = Overflow::on;
	Word newRAValue = Word(sum % fifthPower);
        machine.rA.load(newRAValue);
    } else {
	Word newRAValue = Word(sum);
        machine.rA.load(newRAValue);
    }
    machine.incrementCycles(1);
    machine.incrementCommandPointer();
}

