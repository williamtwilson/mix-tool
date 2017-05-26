#include "Store2.hpp"

Store2::Store2(): Command("ST2", 26) {}

void Store2::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    store(machine, machine.rI2, address, field);
}

