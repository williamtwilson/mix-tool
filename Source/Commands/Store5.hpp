#ifndef STORE5_H
#define STORE5_H

#include "Command.hpp"

class Store5: public Command {
public:
    Store5();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

