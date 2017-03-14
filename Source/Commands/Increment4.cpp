#include "Increment4.hpp"
#include <iostream>

Increment4::Increment4(): Command("INC4", 52) {}

void Increment4::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    long sum = machine->rI4->contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine->overflowToggle = Overflow::on;
        machine->rI4->load(std::make_shared<Word>(sum % fifthPower));
    } else {
        machine->rI4->load(std::make_shared<Word>(sum));
    }
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

