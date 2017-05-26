#ifndef INCREMENT2_H
#define INCREMENT2_H

#include "Command.hpp"

class Increment2: public Command {
public:
    Increment2();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif
