#ifndef COMMAND_H
#define COMMAND_H

#include "../Machine.hpp"
#include <string>
#include <memory>

class Command {
    public:
        unsigned short code;
        std::shared_ptr<std::string> name;

        Command(std::string, unsigned short);

        void execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field);
        static unsigned short fieldForIndexes(unsigned short first, unsigned short last);

    protected:
        void enter(std::shared_ptr<Machine> machine, std::shared_ptr<Register> r, unsigned long address);
        virtual void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field);
        static unsigned short firstFieldIndex(unsigned short field);
        void load(std::shared_ptr<Machine> machine, std::shared_ptr<Register> r, unsigned long address, unsigned short field);
        static unsigned short secondFieldIndex(unsigned short field);
        void store(std::shared_ptr<Machine> machine, std::shared_ptr<Register> reg, unsigned long address, unsigned short field);

    private:
        static unsigned long adjustedAddress(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field);
};

#endif

