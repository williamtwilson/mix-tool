#ifndef STOREZERO_H
#define STOREZERO_H

#include "Command.hpp"

class StoreZero: public Command {
    public:
        StoreZero();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

