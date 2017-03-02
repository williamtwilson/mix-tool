#include "StoreJ.hpp"

StoreJ::StoreJ(): Command("STJ", 32) {}

void StoreJ::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    store(machine, machine->rJ, address, field);
}

