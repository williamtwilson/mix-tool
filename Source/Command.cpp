#include "Command.hpp"

Command::Command(std::string n, unsigned short c): name(new std::string(n)), code(c) {}

void Command::execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field) {}

unsigned short Command::firstFieldIndex(unsigned short field) {
    return field / 8;
}

unsigned short Command::secondFieldIndex(unsigned short field) {
    return field % 8;
}

