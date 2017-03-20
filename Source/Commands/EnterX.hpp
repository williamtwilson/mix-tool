#ifndef ENTERX_H
#define ENTERX_H

#include "Command.hpp"

class EnterX: public Command {
public:
    EnterX();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

