#include "Load2Negative.hpp"

Load2Negative::Load2Negative(): Command("LD2N", 18) {}

void Load2Negative::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    loadNegative(machine, machine->rI2, address, field);
}

