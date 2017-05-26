#ifndef INCREMENT1_H
#define INCREMENT1_H

#include "Command.hpp"

class Increment1: public Command {
public:
    Increment1();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif
