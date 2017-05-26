#include "LoadA.hpp"

LoadA::LoadA(): Command("LDA", 8) {}

void LoadA::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    load(machine, machine.rA, address, field);
}

