#include "EnterA.hpp"

EnterA::EnterA(): Command("ENTA", 48) {}

void EnterA::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    enter(machine->rA, address);
}

