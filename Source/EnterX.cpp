#include "EnterX.hpp"

EnterX::EnterX(): Command("ENTX", 55) {}

void EnterX::execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field) {
    if (index > 0 && index < 7) {
        std::shared_ptr<Register> rI(machine->lookupRegister(index));
        address += rI->contentsToLong();
    }

    std::shared_ptr<Word> w(new Word(address));
    machine->rX->load(w.get());
}

