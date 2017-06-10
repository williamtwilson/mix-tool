#include "JumpOnOverflow.hpp"

JumpOnOverflow::JumpOnOverflow(): Command("JOV", 39) {}

void JumpOnOverflow::executeAdjusted(Machine &machine, unsigned long address, unsigned short) {
    if (machine.overflowToggle == Overflow::on) {
        machine.overflowToggle = Overflow::off;

        Word nextCommand = Word(machine.currentCommandAddress() + 1);

        machine.rJ.load(nextCommand);
        machine.setCommandPointer(address);
    } else {
        machine.incrementCommandPointer();
    }

    machine.incrementCycles(1);
}

