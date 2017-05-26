#ifndef JUMPONOVERFLOW_H
#define JUMPONOVERFLOW_H

#include "Command.hpp"

class JumpOnOverflow: public Command {
public:
    JumpOnOverflow();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field);
};

#endif

