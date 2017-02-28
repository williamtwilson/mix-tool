#include "Load1Negative.hpp"

Load1Negative::Load1Negative(): Command("LD1N", 17) {}

void Load1Negative::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine->rI1, address, field);
}

