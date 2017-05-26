#ifndef LOADX_NEGATIVE_H
#define LOADX_NEGATIVE_H

#include "Command.hpp"

class LoadXNegative: public Command {
public:
    LoadXNegative();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

