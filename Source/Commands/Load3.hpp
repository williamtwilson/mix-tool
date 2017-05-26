#ifndef LOAD3_H
#define LOAD3_H

#include "Command.hpp"

class Load3: public Command {
public:
    Load3();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

