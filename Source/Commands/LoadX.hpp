#ifndef LOADX_H
#define LOADX_H

#include "Command.hpp"

class LoadX: public Command {
    public:
        LoadX();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

