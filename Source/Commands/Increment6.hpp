#ifndef INCREMENT6_H
#define INCREMENT6_H

#include "Command.hpp"

class Increment6: public Command {
public:
    Increment6();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif