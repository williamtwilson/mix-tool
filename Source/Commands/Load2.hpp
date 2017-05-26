#ifndef LOAD2_H
#define LOAD2_H

#include "Command.hpp"

class Load2: public Command {
public:
    Load2();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

