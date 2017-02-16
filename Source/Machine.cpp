#include "Machine.hpp"

Machine::Machine(): 
    overflowToggle(Overflow::off),
    comparisonIndicator(Comparison::less),
    rA(std::make_shared<Register>()),
    rX(std::make_shared<Register>()),
    rI1(std::make_shared<Register>()),
    rI2(std::make_shared<Register>()),
    rI3(std::make_shared<Register>()),
    rI4(std::make_shared<Register>()),
    rI5(std::make_shared<Register>()),
    rI6(std::make_shared<Register>()),
    rJ(std::make_shared<Register>()),
    memory(std::make_shared<Memory>()){}

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

    return std::shared_ptr<Register>(std::make_shared<Register>());
}

std::shared_ptr<Word> Machine::lookupMemoryCell(unsigned long index) {
    return memory->at(index);
}

