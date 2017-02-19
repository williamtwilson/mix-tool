#ifndef LOAD5_H
#define LOAD5_H

#include "Command.hpp"

class Load5: public Command {
    public:
        Load5();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

