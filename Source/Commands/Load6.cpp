#include "Load6.hpp"

Load6::Load6(): Command("LD6", 14) {}

void Load6::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    load(machine, machine.rI6, address, field);
}

