#include "Load3Negative.hpp"

Load3Negative::Load3Negative(): Command("LD3N", 19) {}

void Load3Negative::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine.rI3, address, field);
}

