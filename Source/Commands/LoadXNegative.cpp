#include "LoadXNegative.hpp"

LoadXNegative::LoadXNegative(): Command("LDXN", 23) {}

void LoadXNegative::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine.rX, address, field);
}

