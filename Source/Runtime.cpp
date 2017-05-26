#include "Runtime.hpp"

Runtime::Runtime(): machine(Machine()) {}

void Runtime::executeNextCommand() {
    unsigned long address = machine.currentCommandAddress();
    std::shared_ptr<Word> commandWord = machine.memory.at(address);
    executeWord(commandWord);
}

void Runtime::executeWord(std::shared_ptr<Word> word) {
    unsigned long address = word->address();
    unsigned short command = word->command();
    unsigned short field = word->field();
    unsigned short index = word->index();

    CommandStore::lookupCommandByCode(command, field)->execute(machine, address, index, field);
}

