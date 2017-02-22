#ifndef MACHINE_H
#define MACHINE_H

#include "Comparison.hpp"
#include <iostream>
#include <memory>
#include "Memory.hpp"
#include "Overflow.hpp"
#include "Register.hpp"

class Machine {
    public:
        Overflow overflowToggle;
        unsigned long commandPointer;
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

        std::shared_ptr<Word> lookupMemoryCell(unsigned long);

        void showCell(unsigned long index);
        void showCells(unsigned long start, unsigned long end);

        void showRegisters();
};

#endif

