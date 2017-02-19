#include "Load2.hpp"

Load2::Load2(): Command("LD2", 10) {}

void Load2::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    load(machine, machine->rI2, address, field);
}

