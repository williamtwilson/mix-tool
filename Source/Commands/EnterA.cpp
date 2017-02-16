#include "EnterA.hpp"

EnterA::EnterA(): Command("ENTA", 48) {}

void EnterA::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    std::shared_ptr<Word> w(std::make_shared<Word>(address));
    machine->rA->load(w);
}

