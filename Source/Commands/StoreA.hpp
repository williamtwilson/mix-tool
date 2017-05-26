#ifndef STOREA_H
#define STOREA_H

#include "Command.hpp"

class StoreA: public Command {
public:
    StoreA();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

