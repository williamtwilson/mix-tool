#include "Enter6.hpp"

Enter6::Enter6(): Command("ENT5", 54) {}

void Enter6::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    enter(machine, machine.rI6, address);
}

