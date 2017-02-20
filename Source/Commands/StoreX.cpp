#include "StoreX.hpp"

StoreX::StoreX(): Command("STX", 31) {}

void StoreX::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    store(machine, machine->rX, address, field);
}

