#ifndef INCREMENTX_H
#define INCREMENTX_H

#include "Command.hpp"

class IncrementX: public Command {
public:
    IncrementX();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif
