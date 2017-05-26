#include "StoreZero.hpp"

StoreZero::StoreZero(): Command("STZ", 33) {}

void StoreZero::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    if (address <= 4000) {
        std::shared_ptr<Word> m = machine.lookupMemoryCell(address);
        std::shared_ptr<Word> zero = std::make_shared<Word>(0);

        if (f == 0) {
            m->setSign(Sign::positive);
            f = 1;
        }

        for (int i = l; i >= f; i--) {
            m->setAt(i, zero->at(5 - (l - i)));
        }
        machine.incrementCycles(2);
    }
    machine.incrementCommandPointer();
}

