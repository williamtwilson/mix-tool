#include "StoreA.hpp"

StoreA::StoreA(): Command("STA", 32) {}

void StoreA::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
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

