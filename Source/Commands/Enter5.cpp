#include "Enter5.hpp"

Enter5::Enter5(): Command("ENT5", 53) {}

void Enter5::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    enter(machine, machine.rI5, address);
}

