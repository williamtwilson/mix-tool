#include "StoreA.hpp"

StoreA::StoreA(): Command("STA", 24) {}

void StoreA::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    store(machine, machine.rA, address, field);
}

