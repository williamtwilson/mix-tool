#include "StoreX.hpp"

StoreX::StoreX(): Command("STX", 31) {}

void StoreX::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    store(machine, machine.rX, address, field);
}

