#include "EnterA.hpp"

EnterA::EnterA(): Command("ENTA", 48) {}

void EnterA::execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field) {
    unsigned long aAddress = adjustedAddress(machine, address, index);

    std::shared_ptr<Word> w(std::make_shared<Word>(aAddress));
    machine->rA->load(w);
}

