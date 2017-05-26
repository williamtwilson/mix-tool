#include "CompareX.hpp"

CompareX::CompareX(): Command("CMPX", 63) {}

void CompareX::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    compare(machine, machine.rX, address, field);
}
