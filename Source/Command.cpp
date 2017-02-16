#include "Command.hpp"

Command::Command(std::string n, unsigned short c): name(std::make_shared<std::string>(n)), code(c) {}

unsigned long Command::adjustedAddress(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index) {
    if (index > 0 && index < 7) {
        std::shared_ptr<Register> rI(machine->lookupRegister(index));
        return rI->contentsToLong() + address;
    }

    return address;
}

void Command::execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field) {}

unsigned short Command::fieldForIndexes(unsigned short first, unsigned short last) {
    return first * 8 + last;
}

unsigned short Command::firstFieldIndex(unsigned short field) {
    return field / 8;
}

unsigned short Command::secondFieldIndex(unsigned short field) {
    return field % 8;
}

