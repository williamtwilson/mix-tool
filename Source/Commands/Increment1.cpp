#include "Increment1.hpp"
#include <iostream>

Increment1::Increment1(): Command("INC1", 49) {}

void Increment1::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    long sum = machine->rI1->contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine->overflowToggle = Overflow::on;
        machine->rI1->load(std::make_shared<Word>(sum % fifthPower));
    } else {
        machine->rI1->load(std::make_shared<Word>(sum));
    }
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

