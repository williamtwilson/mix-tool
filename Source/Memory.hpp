#include <memory>
#include <array>
#include "Word.hpp"

#ifndef MEMORY_H
#define MEMORY_H

class Memory {
    public:
        std::shared_ptr<std::array<std::shared_ptr<Word>, 4000>> cells;

        Memory();
        std::shared_ptr<Word> at(unsigned long);
};

#endif

