#ifndef JUMPSAVEJ_H
#define JUMPSAVEJ_H

#include "Command.hpp"

class JumpSaveJ: public Command {
public:
    JumpSaveJ();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field);
};

#endif

