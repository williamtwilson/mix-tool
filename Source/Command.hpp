#include "Machine.hpp"
#include <string>
#include <memory>

#ifndef COMMAND_H
#define COMMAND_H

class Command {
    public:
        std::shared_ptr<std::string> name;
        unsigned short code;

        Command(std::string, unsigned short);

        virtual void execute(Machine *machine, unsigned long address, unsigned short index, unsigned short field);
};

#endif

