#include "headers.hpp"

int main() {
    unsigned long secondByte = 64;
    unsigned long thirdByte = 64 * 64;
    unsigned long fourthByte = 64 * 64 * 64;
    unsigned long fifthByte = 64 * 64 * 64 * 64;
    unsigned long something = 0 - (60 + (30 * secondByte) + (2 * thirdByte) + (3 * fourthByte) + (4 * fifthByte));

    std::shared_ptr<Machine> machine(std::make_shared<Machine>());

    CommandStore::enterA->execute(machine, something, 0, 2);

    CommandStore::storeA->execute(machine, 0000, 0, Command::fieldForIndexes(2, 4));

    CommandStore::storeA->execute(machine, 0001, 0, Command::fieldForIndexes(0, 5));

    CommandStore::loadX->execute(machine, 0001, 0, Command::fieldForIndexes(0, 1));

    machine->showRegisters();
    machine->showCells(0, 20);
}

