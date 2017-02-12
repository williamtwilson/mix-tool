#include "EnterA.hpp"
#include <iostream>

EnterA::EnterA(): Command("ENTA", 48) {}

void EnterA::execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field) {
    if (index > 0 && index < 7) {
        std::shared_ptr<Register> rI(machine->lookupRegister(index));
        address += rI->contentsToLong();
    }

    std::shared_ptr<Word> w(new Word(address));
    machine->rA->load(w.get());
    std::cout << machine->rA->description() << "\n";
}
