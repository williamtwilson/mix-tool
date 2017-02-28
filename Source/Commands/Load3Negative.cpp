#include "Load3Negative.hpp"

Load3Negative::Load3Negative(): Command("LD3N", 19) {}

void Load3Negative::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine->rI3, address, field);
}

