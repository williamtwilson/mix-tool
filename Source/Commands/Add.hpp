#ifndef ADD_H
#define ADD_H

#include "Command.hpp"

class Add: public Command {
public:
    Add();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

