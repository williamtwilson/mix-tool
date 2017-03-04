#ifndef JUMP_H
#define JUMP_H

#include "Command.hpp"

class Jump: public Command {
    public:
        Jump();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field);
};

#endif

