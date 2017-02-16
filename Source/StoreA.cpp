#include "StoreA.hpp"

StoreA::StoreA(): Command("STA", 32) {}

void StoreA::execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field) {
    unsigned long aAddress = adjustedAddress(machine, address, index);

    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    if (address <= 4000) {
        std::shared_ptr<Word> m = machine->lookupMemoryCell(aAddress);
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

