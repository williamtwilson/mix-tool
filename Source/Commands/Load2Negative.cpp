#include "Load2Negative.hpp"

Load2Negative::Load2Negative(): Command("LD2N", 18) {}

void Load2Negative::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine.rI2, address, field);
}

