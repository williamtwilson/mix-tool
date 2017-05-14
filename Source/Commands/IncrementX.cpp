#include "IncrementX.hpp"
#include <iostream>

IncrementX::IncrementX(): Command("INCX", 55) {}

void IncrementX::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    long sum = machine->rX->contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine->overflowToggle = Overflow::on;
	Word newRXValue = Word(sum % fifthPower);
        machine->rX->load(newRXValue);
    } else {
	Word newRXValue = Word(sum);
        machine->rX->load(newRXValue);
    }
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

