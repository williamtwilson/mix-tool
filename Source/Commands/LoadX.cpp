#include "LoadX.hpp"

LoadX::LoadX(): Command("LDX", 15) {}

void LoadX::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    load(machine, machine.rX, address, field);
}

