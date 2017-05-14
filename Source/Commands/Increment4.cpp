#include "Increment4.hpp"
#include <iostream>

Increment4::Increment4(): Command("INC4", 52) {}

void Increment4::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    long sum = machine->rI4.contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine->overflowToggle = Overflow::on;
	Word newR4Value = Word(sum % fifthPower);
        machine->rI4.load(newR4Value);
    } else {
	Word newR4Value = Word(sum);
        machine->rI4.load(newR4Value);
    }
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

