#include "Compare2.hpp"

Compare2::Compare2(): Command("CMP2", 58) {}

void Compare2::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    compare(machine, machine.rI2, address, field);
}
