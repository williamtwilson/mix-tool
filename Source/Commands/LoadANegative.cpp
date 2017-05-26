#include "LoadANegative.hpp"

LoadANegative::LoadANegative(): Command("LDAN", 16) {}

void LoadANegative::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine.rA, address, field);
}

