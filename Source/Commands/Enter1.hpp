#ifndef ENTER1_H
#define ENTER1_H

#include "Command.hpp"

class Enter1: public Command {
public:
    Enter1();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

