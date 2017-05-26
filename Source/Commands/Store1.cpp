#include "Store1.hpp"

Store1::Store1(): Command("ST1", 25) {}

void Store1::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    store(machine, machine.rI1, address, field);
}

