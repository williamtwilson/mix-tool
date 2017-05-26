#include "StoreJ.hpp"

StoreJ::StoreJ(): Command("STJ", 32) {}

void StoreJ::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    store(machine, machine.rJ, address, field);
}

