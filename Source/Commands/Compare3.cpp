#include "Compare3.hpp"

Compare3::Compare3(): Command("CMP3", 59) {}

void Compare3::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    compare(machine, machine->rI3, address, field);
}
