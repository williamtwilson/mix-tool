#include "Jump.hpp"

Jump::Jump(): Command("JMP", 39) {}

void Jump::executeAdjusted(Machine &machine, unsigned long address, unsigned short field) {
    Word nextCommand = Word(machine.currentCommandAddress() + 1);

    machine.rJ.load(nextCommand);
    machine.setCommandPointer(address);
    machine.incrementCycles(1);
}

