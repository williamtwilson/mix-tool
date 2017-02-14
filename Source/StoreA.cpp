#include "StoreA.hpp"

StoreA::StoreA(): Command("STA", 32) {}

void StoreA::execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field) {
    if (index > 0 && index < 7) {
        std::shared_ptr<Register> rI(machine->lookupRegister(index));
        address += rI->contentsToLong();
    }

    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    if (address <= 4000) {
        std::shared_ptr<Word> m = machine->lookupMemoryCell(address);
        std::shared_ptr<Word> rAWord = machine->rA->read();

        if (f == 0) {
            m->setSign(rAWord->sign());
            f = 1;
        }

        for (int i = l; i >= f; i--) {
            m->setAt(i, rAWord->at(5 - (l - i)));
        }
    }
}

