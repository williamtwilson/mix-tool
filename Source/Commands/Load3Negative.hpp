#ifndef LOAD3_NEGATIVE_H
#define LOAD3_NEGATIVE_H

#include "Command.hpp"

class Load3Negative: public Command {
public:
    Load3Negative();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

