#include "Enter1.hpp"

Enter1::Enter1(): Command("ENT1", 49) {}

void Enter1::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    std::shared_ptr<Word> w(std::make_shared<Word>(address));
    machine->rI1->load(w);
}

