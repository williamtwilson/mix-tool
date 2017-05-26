#include "EnterX.hpp"

EnterX::EnterX(): Command("ENTX", 55) {}

void EnterX::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    enter(machine, machine.rX, address);
}

