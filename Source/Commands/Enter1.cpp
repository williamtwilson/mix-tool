#include "Enter1.hpp"

Enter1::Enter1(): Command("ENT1", 49) {}

void Enter1::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    enter(machine, machine.rI1, address);
}

