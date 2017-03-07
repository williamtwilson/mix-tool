#ifndef JUMPONNOOVERFLOW_H
#define JUMPONNOOVERFLOW_H

#include "Command.hpp"

class JumpOnNoOverflow: public Command {
    public:
        JumpOnNoOverflow();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field);
};

#endif

