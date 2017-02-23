#include "EnterX.hpp"

EnterX::EnterX(): Command("ENTX", 55) {}

void EnterX::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    enter(machine, machine->rX, address);
}

