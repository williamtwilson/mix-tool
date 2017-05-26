#ifndef ENTER3_H
#define ENTER3_H

#include "Command.hpp"

class Enter3: public Command {
public:
    Enter3();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

