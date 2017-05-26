#include "NoOperation.hpp"

NoOperation::NoOperation(): Command("NOP", 0) {}

void NoOperation::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    machine.incrementCycles(1);
    machine.incrementCommandPointer();
}

