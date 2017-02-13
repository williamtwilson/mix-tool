#include "Machine.hpp"

Machine::Machine(): 
    overflowToggle(Overflow::off),
    comparisonIndicator(Comparison::less),
    rA(new Register()),
    rX(new Register()),
    rI1(new Register()),
    rI2(new Register()),
    rI3(new Register()),
    rI4(new Register()),
    rI5(new Register()),
    rI6(new Register()),
    rJ(new Register()) {}

std::shared_ptr<Register> Machine::lookupRegister(unsigned short index) {
    switch (index) {
        case 1:
            return rI1;
            break;
        case 2:
            return rI2;
            break;
        case 3:
            return rI3;
            break;
        case 4:
            return rI4;
            break;
        case 5:
            return rI5;
            break;
        case 6:
            return rI6;
            break;
    }

    return std::shared_ptr<Register>(new Register());
}

std::shared_ptr<Word> Machine::lookupMemoryCell(unsigned long index) {
    return memory->at(index);
}

