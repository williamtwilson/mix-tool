#ifndef ENTER4_H
#define ENTER4_H

#include "Command.hpp"

class Enter4: public Command {
    public:
        Enter4();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

