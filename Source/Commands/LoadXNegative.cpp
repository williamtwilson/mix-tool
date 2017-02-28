#include "LoadXNegative.hpp"

LoadXNegative::LoadXNegative(): Command("LDXN", 23) {}

void LoadXNegative::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine->rX, address, field);
}

