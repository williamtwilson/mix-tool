#ifndef INCREMENTX_H
#define INCREMENTX_H

#include "Command.hpp"

class IncrementX: public Command {
    public:
        IncrementX();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif
