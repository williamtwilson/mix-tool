#include "Command.hpp"

Command::Command(std::string n, unsigned short c): name(new std::string(n)), code(c) {}

void Command::execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field) {}
