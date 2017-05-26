#ifndef COMPARE6_H
#define COMPARE6_H

#include "Command.hpp"

class Compare6: public Command {
public:
    Compare6();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif
