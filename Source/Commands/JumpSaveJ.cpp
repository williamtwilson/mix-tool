#include "JumpSaveJ.hpp"

JumpSaveJ::JumpSaveJ(): Command("JSJ", 39) {}

void JumpSaveJ::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    machine->setCommandPointer(address);
    machine->incrementCycles(1);
}

