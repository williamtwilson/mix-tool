#ifndef LOAD4_NEGATIVE_H
#define LOAD4_NEGATIVE_H

#include "Command.hpp"

class Load4Negative: public Command {
    public:
        Load4Negative();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

