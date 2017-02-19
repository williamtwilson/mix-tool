#ifndef LOAD4_H
#define LOAD4_H

#include "Command.hpp"

class Load4: public Command {
    public:
        Load4();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

