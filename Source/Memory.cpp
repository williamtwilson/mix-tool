#include "Memory.hpp"
#include <iostream>

Memory::Memory(): cells(new std::array<std::shared_ptr<Word>, 4000>) {
    for (int i = 0; i < 4000; i++) {
        std::shared_ptr<Word> word(new Word(0));
        cells->at(i) = word;
    }
};

std::shared_ptr<Word> Memory::at(unsigned long index) {
    return cells->at(index);
}

