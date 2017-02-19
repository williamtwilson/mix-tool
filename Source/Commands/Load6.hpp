#ifndef LOAD6_H
#define LOAD6_H

#include "Command.hpp"

class Load6: public Command {
    public:
        Load6();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

