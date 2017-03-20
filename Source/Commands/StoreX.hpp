#ifndef STOREX_H
#define STOREX_H

#include "Command.hpp"

class StoreX: public Command {
public:
    StoreX();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

