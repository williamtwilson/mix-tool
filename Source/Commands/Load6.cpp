#include "Load6.hpp"

Load6::Load6(): Command("LD6", 14) {}

void Load6::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    load(machine, machine->rI6, address, field);
}

