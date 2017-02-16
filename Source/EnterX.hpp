#include "Command.hpp"

#ifndef ENTERX_H
#define ENTERX_H

class EnterX: public Command {
    public:
        EnterX();
        void execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field) override;
};

#endif

