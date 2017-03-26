#include "Compare5.hpp"

Compare5::Compare5(): Command("CMP5", 61) {}

void Compare5::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    compare(machine, machine->rI5, address, field);
}
