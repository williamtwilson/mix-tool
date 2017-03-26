#ifndef COMPARE4_H
#define COMPARE4_H

#include "Command.hpp"

class Compare4: public Command {
public:
    Compare4();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif
