#include "Enter2.hpp"

Enter2::Enter2(): Command("ENT2", 50) {}

void Enter2::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    enter(machine->rI2, address);
}

