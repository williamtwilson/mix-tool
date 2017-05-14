#include "Machine.hpp"

Machine::Machine(): 
    overflowToggle(Overflow::off),
    comparisonIndicator(Comparison::less),
    rA(Register()),
    rX(Register()),
    rI1(Register()),
    rI2(Register()),
    rI3(Register()),
    rI4(Register()),
    rI5(Register()),
    rI6(Register()),
    rJ(Register()),
    memory(std::make_shared<Memory>()),
    commandPointer(0),
    cyclesPassed(0){}

unsigned long Machine::currentCommandAddress() {
    return commandPointer;
}

void Machine::incrementCommandPointer() {
    ++commandPointer;
}

void Machine::incrementCycles(unsigned long cycles) {
    cyclesPassed += cycles;
}

Register Machine::lookupRegister(unsigned short index) {
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

    return Register(Register());
}

std::shared_ptr<Word> Machine::lookupMemoryCell(unsigned long index) {
    return memory->at(index);
}

void Machine::showCell(unsigned long index) {
    if (index >= 4000) {
        return;
    }

    if (index < 10) {
        std::cout << "000";
    } else if (index < 100) {
        std::cout << "00";
    } else if (index < 1000) {
        std::cout << "0";
    }

    std::cout << std::to_string(index) << " : ";

    std::shared_ptr<Word> w = lookupMemoryCell(index);

    std::cout << w->description() << "\n";
}

void Machine::setCommandPointer(unsigned long address) {
    commandPointer = address;
}

void Machine::showCells(unsigned long start, unsigned long end) {
    for (int i = start; i < end; i++) {
        showCell(i);
    }
}

void Machine::showRegisters() {
    std::cout
        << "RA  : " << rA.description() << "\n"
        << "RX  : " << rX.description() << "\n"
        << "RI1 : " << rI1.description() << "\n"
        << "RI2 : " << rI2.description() << "\n"
        << "RI3 : " << rI3.description() << "\n"
        << "RI4 : " << rI4.description() << "\n"
        << "RI5 : " << rI5.description() << "\n"
        << "RI6 : " << rI6.description() << "\n"
        << "RJ  : " << rJ.description() << "\n";
}

unsigned long Machine::totalCycles() {
    return cyclesPassed;
}

