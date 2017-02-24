#include "NoOperation.hpp"

NoOperation::NoOperation(): Command("NOP", 0) {}

void NoOperation::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

