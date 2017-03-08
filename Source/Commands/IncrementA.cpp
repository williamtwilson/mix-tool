#include "IncrementA.hpp"
#include <iostream>

IncrementA::IncrementA(): Command("INCA", 48) {}

void IncrementA::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    long sum = machine->rA->contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine->overflowToggle = Overflow::on;
        machine->rA->load(std::make_shared<Word>(sum % fifthPower));
    } else {
        machine->rA->load(std::make_shared<Word>(sum));
    }
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

