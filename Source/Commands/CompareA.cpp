#include "CompareA.hpp"

CompareA::CompareA(): Command("CMPA", 56) {}

void CompareA::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    compare(machine, machine.rA, address, field);
}
