#ifndef LOAD5_NEGATIVE_H
#define LOAD5_NEGATIVE_H

#include "Command.hpp"

class Load5Negative: public Command {
public:
    Load5Negative();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

