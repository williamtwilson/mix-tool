#ifndef STORE2_H
#define STORE2_H

#include "Command.hpp"

class Store2: public Command {
    public:
        Store2();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

