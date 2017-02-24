#ifndef MEMORY_H
#define MEMORY_H

#include <memory>
#include <array>
#include "Word.hpp"

class Memory {
    public:
        std::shared_ptr<std::array<std::shared_ptr<Word>, 4000>> cells;

        Memory();
        std::shared_ptr<Word> at(unsigned long);
        void setAt(unsigned long index, std::shared_ptr<Word> value);
};

#endif

