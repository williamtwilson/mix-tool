#include "Increment3.hpp"
#include <iostream>

Increment3::Increment3(): Command("INC3", 51) {}

void Increment3::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    long sum = machine->rI3->contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine->overflowToggle = Overflow::on;
        machine->rI3->load(std::make_shared<Word>(sum % fifthPower));
    } else {
        machine->rI3->load(std::make_shared<Word>(sum));
    }
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

