#ifndef STORE1_H
#define STORE1_H

#include "Command.hpp"

class Store1: public Command {
public:
    Store1();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

