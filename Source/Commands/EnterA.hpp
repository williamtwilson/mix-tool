#include "Command.hpp"

#ifndef ENTERA_H
#define ENTERA_H

class EnterA: public Command {
    public:
        EnterA();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif