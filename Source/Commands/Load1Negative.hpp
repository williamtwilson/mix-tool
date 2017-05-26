#ifndef LOAD1_NEGATIVE_H
#define LOAD1_NEGATIVE_H

#include "Command.hpp"

class Load1Negative: public Command {
public:
    Load1Negative();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

