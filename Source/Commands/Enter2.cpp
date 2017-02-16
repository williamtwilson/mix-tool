#include "Enter2.hpp"

Enter2::Enter2(): Command("ENT2", 50) {}

void Enter2::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    std::shared_ptr<Word> w(std::make_shared<Word>(address));
    machine->rI2->load(w);
}

