#ifndef ENTERA_H
#define ENTERA_H

#include "Command.hpp"

class EnterA: public Command {
public:
    EnterA();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif
