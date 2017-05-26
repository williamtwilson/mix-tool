#include "Compare4.hpp"

Compare4::Compare4(): Command("CMP4", 60) {}

void Compare4::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    compare(machine, machine.rI4, address, field);
}
