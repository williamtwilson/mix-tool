#include "Load3.hpp"

Load3::Load3(): Command("LD3", 11) {}

void Load3::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    load(machine, machine->rI3, address, field);
}

