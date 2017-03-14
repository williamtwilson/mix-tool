#include "Increment2.hpp"
#include <iostream>

Increment2::Increment2(): Command("INC2", 50) {}

void Increment2::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    long sum = machine->rI2->contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine->overflowToggle = Overflow::on;
        machine->rI2->load(std::make_shared<Word>(sum % fifthPower));
    } else {
        machine->rI2->load(std::make_shared<Word>(sum));
    }
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

