#ifndef ENTER6_H
#define ENTER6_H

#include "Command.hpp"

class Enter6: public Command {
public:
    Enter6();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

