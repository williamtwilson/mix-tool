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

        static unsigned long adjustedAddress(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index);

        virtual void execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field);
        static unsigned short fieldForIndexes(unsigned short first, unsigned short last);
        static unsigned short firstFieldIndex(unsigned short field);
        static unsigned short secondFieldIndex(unsigned short field);
};

#endif

