#include "LoadA.hpp"

LoadA::LoadA(): Command("LDA", 8) {}

void LoadA::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    load(machine, machine->rA, address, field);
}

