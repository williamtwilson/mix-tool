#ifndef STORE6_H
#define STORE6_H

#include "Command.hpp"

class Store6: public Command {
public:
    Store6();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

