#ifndef LOAD6_NEGATIVE_H
#define LOAD6_NEGATIVE_H

#include "Command.hpp"

class Load6Negative: public Command {
public:
    Load6Negative();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

