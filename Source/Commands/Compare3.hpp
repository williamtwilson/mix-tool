#ifndef COMPARE3_H
#define COMPARE3_H

#include "Command.hpp"

class Compare3: public Command {
public:
    Compare3();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif
