#include "Increment5.hpp"
#include <iostream>

Increment5::Increment5(): Command("INC5", 53) {}

void Increment5::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    long sum = machine->rI5->contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine->overflowToggle = Overflow::on;
	Word newR5Value = Word(sum % fifthPower);
        machine->rI5->load(newR5Value);
    } else {
	Word newR5Value = Word(sum);
        machine->rI5->load(newR5Value);
    }
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

