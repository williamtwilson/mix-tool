#ifndef STORE3_H
#define STORE3_H

#include "Command.hpp"

class Store3: public Command {
public:
    Store3();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

