#ifndef STORE4_H
#define STORE4_H

#include "Command.hpp"

class Store4: public Command {
public:
    Store4();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

