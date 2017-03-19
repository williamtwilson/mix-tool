#ifndef COMPAREA_H
#define COMPAREA_H

#include "Command.hpp"

class CompareA: public Command {
public:
    CompareA();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif
