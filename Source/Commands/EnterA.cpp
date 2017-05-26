#include "EnterA.hpp"

EnterA::EnterA(): Command("ENTA", 48) {}

void EnterA::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    enter(machine, machine.rA, address);
}

