#include "Store3.hpp"

Store3::Store3(): Command("ST3", 27) {}

void Store3::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    store(machine, machine.rI3, address, field);
}

