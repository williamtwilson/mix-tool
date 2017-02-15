#include "EnterX.hpp"

EnterX::EnterX(): Command("ENTX", 55) {}

void EnterX::execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field) {
    unsigned long aAddress = adjustedAddress(machine, address, index);

    std::shared_ptr<Word> w(new Word(aAddress));
    machine->rX->load(w.get());
}

