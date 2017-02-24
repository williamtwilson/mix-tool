#include "Memory.hpp"
#include <iostream>

Memory::Memory(): cells(std::make_shared<std::array<std::shared_ptr<Word>, 4000>>()) {
    for (int i = 0; i < 4000; i++) {
        std::shared_ptr<Word> word(std::make_shared<Word>(0));
        cells->at(i) = word;
    }
};

std::shared_ptr<Word> Memory::at(unsigned long index) {
    return cells->at(index);
}

void Memory::setAt(unsigned long index, std::shared_ptr<Word> value) {
    cells->at(index) = value;
}

