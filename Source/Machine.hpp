#include <memory>
#include "Comparison.hpp"
#include "Memory.hpp"
#include "Overflow.hpp"
#include "Register.hpp"

#ifndef MACHINE_H
#define MACHINE_H

class Machine {
    public:
        Overflow overflowToggle;
        Comparison comparisonIndicator;

        std::shared_ptr<Register> rA;
        std::shared_ptr<Register> rX;
        std::shared_ptr<Register> rI1;
        std::shared_ptr<Register> rI2;
        std::shared_ptr<Register> rI3;
        std::shared_ptr<Register> rI4;
        std::shared_ptr<Register> rI5;
        std::shared_ptr<Register> rI6;
        std::shared_ptr<Register> rJ;

        std::shared_ptr<Memory> memory;

        Machine();

        std::shared_ptr<Register> lookupRegister(unsigned short);
};

#endif

