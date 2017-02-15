#include "Enter1.hpp"

Enter1::Enter1(): Command("ENT1", 49) {}

void Enter1::execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field) {
    unsigned long aAddress = adjustedAddress(machine, address, index);

    std::shared_ptr<Word> w(new Word(aAddress));
    machine->rI1->load(w.get());
}
