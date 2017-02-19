#include "Enter3.hpp"

Enter3::Enter3(): Command("ENT3", 51) {}

void Enter3::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    enter(machine->rI3, address);
}

