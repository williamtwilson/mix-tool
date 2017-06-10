#include "NoOperation.hpp"

NoOperation::NoOperation(): Command("NOP", 0) {}

void NoOperation::executeAdjusted(Machine &machine, unsigned long, unsigned short) {
    machine.incrementCycles(1);
    machine.incrementCommandPointer();
}

