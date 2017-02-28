#include "Load5Negative.hpp"

Load5Negative::Load5Negative(): Command("LD5N", 21) {}

void Load5Negative::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine->rI5, address, field);
}

