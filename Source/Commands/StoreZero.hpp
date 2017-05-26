#ifndef STOREZERO_H
#define STOREZERO_H

#include "Command.hpp"

class StoreZero: public Command {
public:
    StoreZero();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

