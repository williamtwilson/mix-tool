#include "Load4Negative.hpp"

Load4Negative::Load4Negative(): Command("LD4N", 20) {}

void Load4Negative::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine->rI4, address, field);
}

