#include "Load5.hpp"

Load5::Load5(): Command("LD5", 13) {}

void Load5::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    load(machine, machine->rI5, address, field);
}

