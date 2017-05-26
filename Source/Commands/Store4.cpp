#include "Store4.hpp"

Store4::Store4(): Command("ST4", 28) {}

void Store4::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    store(machine, machine.rI4, address, field);
}

