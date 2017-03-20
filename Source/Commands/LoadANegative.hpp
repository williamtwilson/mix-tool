#ifndef LOADA_NEGATIVE_H
#define LOADA_NEGATIVE_H

#include "Command.hpp"

class LoadANegative: public Command {
public:
    LoadANegative();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif

