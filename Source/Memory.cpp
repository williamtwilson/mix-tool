#include "Memory.hpp"

Memory::Memory(): cells(new std::array<std::shared_ptr<Word>, 4000>) {};

std::shared_ptr<Word> Memory::at(unsigned long index) {
    return cells->at(index);
}

