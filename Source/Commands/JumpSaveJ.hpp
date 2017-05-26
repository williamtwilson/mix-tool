#ifndef JUMPSAVEJ_H
#define JUMPSAVEJ_H

#include "Command.hpp"

class JumpSaveJ: public Command {
public:
    JumpSaveJ();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field);
};

#endif

