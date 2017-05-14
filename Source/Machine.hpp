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
    Comparison comparisonIndicator;

    Register rA;
    Register rX;
    Register rI1;
    Register rI2;
    Register rI3;
    Register rI4;
    Register rI5;
    Register rI6;
    Register rJ;

    std::shared_ptr<Memory> memory;

    Machine();

    unsigned long currentCommandAddress();

    void incrementCommandPointer();
    void incrementCycles(unsigned long cycles);

    Register lookupRegister(unsigned short);

    std::shared_ptr<Word> lookupMemoryCell(unsigned long);

    void setCommandPointer(unsigned long address);

    void showCell(unsigned long index);
    void showCells(unsigned long start, unsigned long end);

    void showRegisters();

    unsigned long totalCycles();

private:
    unsigned long commandPointer;
    unsigned long cyclesPassed;
};

#endif

