#ifndef COMPARE1_H
#define COMPARE1_H

#include "Command.hpp"

class Compare1: public Command {
public:
    Compare1();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif