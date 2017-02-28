#include "Load6Negative.hpp"

Load6Negative::Load6Negative(): Command("LD6N", 22) {}

void Load6Negative::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine->rI6, address, field);
}

