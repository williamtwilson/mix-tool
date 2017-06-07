#ifndef COMMAND_H
#define COMMAND_H

#include "Source/Machine.hpp"
#include <string>
#include <memory>

class Command {
    static unsigned long adjustedAddress(Machine &machine, unsigned long address, unsigned short field);
public:
    unsigned short code;
    std::shared_ptr<std::string> name;

    Command(std::string, unsigned short);

    void execute(Machine &machine, unsigned long address, unsigned short index, unsigned short field);
    static unsigned short fieldForIndexes(unsigned short first, unsigned short last);

protected:
    virtual void executeAdjusted(Machine &machine, unsigned long address, unsigned short field);
    static unsigned short firstFieldIndex(unsigned short field);
    static unsigned short secondFieldIndex(unsigned short field);
};

#endif

