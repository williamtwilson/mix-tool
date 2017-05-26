#include "Store5.hpp"

Store5::Store5(): Command("ST5", 29) {}

void Store5::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    store(machine, machine.rI5, address, field);
}

