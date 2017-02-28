#ifndef LOAD2_NEGATIVE_H
#define LOAD2_NEGATIVE_H

#include "Command.hpp"

class Load2Negative: public Command {
    public:
        Load2Negative();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

