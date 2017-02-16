#include "Machine.hpp"
#include <string>
#include <memory>

#ifndef COMMAND_H
#define COMMAND_H

class Command {
    public:
        unsigned short code;
        std::shared_ptr<std::string> name;

        Command(std::string, unsigned short);

        void execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field);
        static unsigned short fieldForIndexes(unsigned short first, unsigned short last);

    protected:
        virtual void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field);
        static unsigned short firstFieldIndex(unsigned short field);
        static unsigned short secondFieldIndex(unsigned short field);

    private:
        static unsigned long adjustedAddress(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index);
};

#endif

