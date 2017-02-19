#include "Enter6.hpp"

Enter6::Enter6(): Command("ENT5", 54) {}

void Enter6::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    enter(machine->rI6, address);
}

