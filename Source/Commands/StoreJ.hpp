#ifndef STOREJ_H
#define STOREJ_H

#include "Command.hpp"

class StoreJ: public Command {
    public:
        StoreJ();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

