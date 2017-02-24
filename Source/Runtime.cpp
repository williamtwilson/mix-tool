#include "Runtime.hpp"

Runtime::Runtime(): machine(std::make_shared<Machine>()) {}

void Runtime::executeWord(std::shared_ptr<Word> word) {
    unsigned long address = word->address();
    unsigned short command = word->command();
    unsigned short field = word->field();
    unsigned short index = word->index();

    CommandStore::lookupCommandByCode(command, field)->execute(machine, address, index, field);
}

