#include "LoadX.hpp"

LoadX::LoadX(): Command("LDX", 15) {}

void LoadX::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    if (address <= 4000) {
        std::shared_ptr<Word> m = machine->lookupMemoryCell(address);

        std::shared_ptr<Word> tmp(std::make_shared<Word>());

        if (f == 0) {
            tmp->setSign(m->sign());
            f = 1;
        }

        for (int i = 5; l >= f; i--, l--) {
            tmp->setAt(i, m->at(l));
        }

        machine->rX->load(tmp);
    }
}

