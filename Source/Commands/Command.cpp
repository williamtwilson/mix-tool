#include "Command.hpp"

Command::Command(std::string n, unsigned short c): code(c), name(std::make_shared<std::string>(n)) {}

unsigned long Command::adjustedAddress(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index) {
    if (index > 0 && index < 7) {
        std::shared_ptr<Register> rI = machine->lookupRegister(index);
        return rI->contentsToLong() + address;
    }

    return address;
}

void Command::compare(std::shared_ptr<Machine> machine, std::shared_ptr<Register> r, unsigned long address, unsigned short field) {
    std::shared_ptr<Word> cell = machine->lookupMemoryCell(address);

    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    long rValue = 0;
    long cellValue = 0;

    bool setSign = f == 0;

    if (f == 0) {
	++f;
    }

    for (int i = f; i <= l; ++i) {
	rValue *= 64;
	cellValue *= 64;

	rValue += r->read().at(i);
	cellValue += cell->at(i);
    }

    if (setSign && r->read().sign() == Sign::negative) {
	rValue = 0 - rValue;
    }

    if (setSign && cell->sign() == Sign::negative) {
	cellValue = 0 - cellValue;
    }

    if (rValue > cellValue) {
	machine->comparisonIndicator = Comparison::greater;
    } else if (rValue < cellValue) {
	machine->comparisonIndicator = Comparison::less;
    } else {
	machine->comparisonIndicator = Comparison::equal;
    }

    machine->incrementCycles(2);
    machine->incrementCommandPointer();
}

void Command::enter(std::shared_ptr<Machine> machine, std::shared_ptr<Register> r, unsigned long address) {
    Word w = Word(address);
    r->load(w);
    machine->incrementCycles(1);
    machine->incrementCommandPointer();
}

void Command::executeAdjusted(std::shared_ptr<Machine> machine, unsigned long address, unsigned short field) {}

void Command::execute(std::shared_ptr<Machine> machine, unsigned long address, unsigned short index, unsigned short field) {
    unsigned long adjustedIndex = adjustedAddress(machine, address, index);

    executeAdjusted(machine, adjustedIndex, field);
}

unsigned short Command::fieldForIndexes(unsigned short first, unsigned short last) {
    return first * 8 + last;
}

unsigned short Command::firstFieldIndex(unsigned short field) {
    return field / 8;
}

void Command::load(std::shared_ptr<Machine> machine, std::shared_ptr<Register> r, unsigned long address, unsigned short field) {
    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    if (address <= 4000) {
        std::shared_ptr<Word> m = machine->lookupMemoryCell(address);

        Word tmp = Word();

        if (f == 0) {
            tmp.setSign(m->sign());
            f = 1;
        }

        for (int i = 5; l >= f; i--, l--) {
            tmp.setAt(i, m->at(l));
        }

        r->load(tmp);
        machine->incrementCycles(2);
    }
    machine->incrementCommandPointer();
}

void Command::loadNegative(std::shared_ptr<Machine> machine, std::shared_ptr<Register> r, unsigned long address, unsigned short field) {
    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    if (address <= 4000) {
        std::shared_ptr<Word> m = machine->lookupMemoryCell(address);

        Word tmp = Word();

        if (f == 0) {
            if (m->sign() == Sign::positive) {
                tmp.setSign(Sign::negative);
            } else {
                tmp.setSign(Sign::positive);
            }
            f = 1;
        }

        for (int i = 5; l >= f; i--, l--) {
            tmp.setAt(i, m->at(l));
        }

        r->load(tmp);
        machine->incrementCycles(2);
    }
    machine->incrementCommandPointer();
}

unsigned short Command::secondFieldIndex(unsigned short field) {
    return field % 8;
}

void Command::store(std::shared_ptr<Machine> machine, std::shared_ptr<Register> reg, unsigned long address, unsigned short field) {
    unsigned short f = firstFieldIndex(field);
    unsigned short l = secondFieldIndex(field);

    if (address <= 4000) {
        std::shared_ptr<Word> m = machine->lookupMemoryCell(address);
        Word regWord = reg->read();

        if (f == 0) {
            m->setSign(regWord.sign());
            f = 1;
        }

        for (int i = l; i >= f; i--) {
            m->setAt(i, regWord.at(5 - (l - i)));
        }
        machine->incrementCycles(2);
    }
    machine->incrementCommandPointer();
}

