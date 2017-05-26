#ifndef NO_OPERATION_H
#define NO_OPERATION_H

#include "Command.hpp"

class NoOperation: public Command {
public:
    NoOperation();

protected:
    void executeAdjusted(Machine &machine, unsigned long address, unsigned short field) override;
};

#endif
