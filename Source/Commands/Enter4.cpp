#include "Enter4.hpp"

Enter4::Enter4(): Command("ENT4", 52) {}

void Enter4::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    enter(machine, machine->rI4, address);
}

