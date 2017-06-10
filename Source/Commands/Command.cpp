#include "Command.hpp"

Command::Command(std::string n, unsigned short c): code(c), name(std::make_shared<std::string>(n)) {}

unsigned long Command::adjustedAddress(Machine &machine, unsigned long address, unsigned short index) {
    if (index > 0 && index < 7) {
        Register rI = machine.lookupRegister(index);
        return rI.contentsToLong() + address;
    }

    return address;
}

void Command::executeAdjusted(Machine &, unsigned long, unsigned short) {}

void Command::execute(Machine &machine, unsigned long address, unsigned short index, unsigned short field) {
    unsigned long adjustedIndex = adjustedAddress(machine, address, index);

    executeAdjusted(machine, adjustedIndex, field);
}

unsigned short Command::fieldForIndexes(unsigned short first, unsigned short last) {
    return first * 8 + last;
}

unsigned short Command::firstFieldIndex(unsigned short field) {
    return field / 8;
}

unsigned short Command::secondFieldIndex(unsigned short field) {
    return field % 8;
}
