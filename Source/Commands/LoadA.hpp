#ifndef LOADA_H
#define LOADA_H

#include "Command.hpp"

class LoadA: public Command {
public:
    LoadA();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif

