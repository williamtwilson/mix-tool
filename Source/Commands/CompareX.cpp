#include "CompareX.hpp"

CompareX::CompareX(): Command("CMPX", 63) {}

void CompareX::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    compare(machine, machine->rX, address, field);
}
