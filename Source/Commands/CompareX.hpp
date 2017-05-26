#ifndef COMPAREX_H
#define COMPAREX_H

#include "Command.hpp"

class CompareX: public Command {
public:
    CompareX();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif
