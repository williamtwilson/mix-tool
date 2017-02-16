#include "Enter1.hpp"

Enter1::Enter1(): Command("ENT1", 49) {}

void Enter1::execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field) {
    unsigned long aAddress = adjustedAddress(machine, address, index);

    std::shared_ptr<Word> w(std::make_shared<Word>(aAddress));
    machine->rI1->load(w);
}
