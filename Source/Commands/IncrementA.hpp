#ifndef INCREMENTA_H
#define INCREMENTA_H

#include "Command.hpp"

class IncrementA: public Command {
public:
    IncrementA();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif
