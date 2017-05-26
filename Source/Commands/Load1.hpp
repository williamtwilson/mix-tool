#ifndef LOAD1_H
#define LOAD1_H

#include "Command.hpp"

class Load1: public Command {
public:
    Load1();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

