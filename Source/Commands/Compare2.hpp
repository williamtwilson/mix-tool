#ifndef COMPARE2_H
#define COMPARE2_H

#include "Command.hpp"

class Compare2: public Command {
public:
    Compare2();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif
