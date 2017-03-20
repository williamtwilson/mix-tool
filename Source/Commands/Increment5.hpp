#ifndef INCREMENT5_H
#define INCREMENT5_H

#include "Command.hpp"

class Increment5: public Command {
public:
    Increment5();

protected:
    void executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) override;
};

#endif
