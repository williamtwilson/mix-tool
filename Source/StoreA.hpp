#include "Command.hpp"

#ifndef STOREA_H
#define STOREA_H

class StoreA: public Command {
    public:
        StoreA();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

