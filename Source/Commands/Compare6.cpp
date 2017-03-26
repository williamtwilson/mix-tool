#include "Compare6.hpp"

Compare6::Compare6(): Command("CMP6", 62) {}

void Compare6::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    compare(machine, machine->rI6, address, field);
}
