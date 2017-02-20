#include "Store6.hpp"

Store6::Store6(): Command("ST6", 30) {}

void Store6::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    store(machine, machine->rI6, address, field);
}

