#include "Add.hpp"
#include <iostream>

Add::Add(): Command("ADD", 1) {}

void Add::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    if (address <= 4000) {
        std::shared_ptr<Word> memoryCell = machine->memory->at(address);

        std::shared_ptr<Word> tmp = std::make_shared<Word>();

        if (f == 0) {
            tmp->setSign(memoryCell->sign());
            f = 1;
        }

        for (int i = 5; l >= f; i--, l--) {
            tmp->setAt(i, memoryCell->at(l));
        }

        long sum = machine->rA->contentsToLong() + tmp->toLong();
        unsigned long fifthPower = 64 * 64 * 64 * 64 * 64;

        if (sum > fifthPower) {
            machine->overflowToggle = Overflow::on;
            machine->rA->load(std::make_shared<Word>(sum % fifthPower));
        } else {
            machine->rA->load(std::make_shared<Word>(sum));
        }
        machine->incrementCycles(2);
    }
    machine->incrementCommandPointer();
}

