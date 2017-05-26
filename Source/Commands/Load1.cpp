#include "Load1.hpp"

Load1::Load1(): Command("LD1", 9) {}

void Load1::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    load(machine, machine.rI1, address, field);
}

