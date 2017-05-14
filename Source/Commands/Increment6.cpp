#include "Increment6.hpp"
#include <iostream>

Increment6::Increment6(): Command("INC6", 54) {}

void Increment6::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    long sum = machine->rI6.contentsToLong() + address;
    unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

    if (sum > fifthPower) {
        machine->overflowToggle = Overflow::on;
	Word newR6Value = Word(sum % fifthPower);
        machine->rI6.load(newR6Value);
    } else {
	Word newR6Value = Word(sum);
        machine->rI6.load(newR6Value);
    }
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

