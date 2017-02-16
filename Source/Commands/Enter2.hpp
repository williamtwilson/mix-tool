#include "Command.hpp"

#ifndef ENTER2_H
#define ENTER2_H

class Enter2: public Command {
    public:
        Enter2();

    protected:
        void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

