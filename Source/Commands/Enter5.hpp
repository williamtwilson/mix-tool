#ifndef ENTER5_H
#define ENTER5_H

#include "Command.hpp"

class Enter5: public Command {
    public:
        Enter5();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

