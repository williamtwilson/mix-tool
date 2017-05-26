#include "Store6.hpp"

Store6::Store6(): Command("ST6", 30) {}

void Store6::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    store(machine, machine.rI6, address, field);
}

