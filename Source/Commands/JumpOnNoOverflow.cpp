#include "JumpOnNoOverflow.hpp"

JumpOnNoOverflow::JumpOnNoOverflow(): Command("JOV", 39) {}

void JumpOnNoOverflow::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {
    if (machine->overflowToggle == Overflow::on) {
        machine->overflowToggle = Overflow::off;

        machine->incrementCommandPointer();
    } else {
        std::shared_ptr<Word> nextCommand = std::make_shared<Word>(machine->currentCommandAddress() + 1);

        machine->rJ->load(nextCommand);
        machine->setCommandPointer(address);
    }

    machine->incrementCycles(1);
}

