#include "Load4.hpp"

Load4::Load4(): Command("LD4", 12) {}

void Load4::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    load(machine, machine->rI4, address, field);
}

