#include "Compare1.hpp"

Compare1::Compare1(): Command("CMP1", 57) {}

void Compare1::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    compare(machine, machine->rI1, address, field);
}
