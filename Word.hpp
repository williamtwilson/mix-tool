#include <array>
#include <string>
#include <memory>
#include "Byte.hpp"
#include "Sign.hpp"

#ifndef WORD_H
#define WORD_H

class Word {
    public:
        Word();
        Word(Sign, Byte, Byte, Byte, Byte, Byte);
        Word(long);

        std::string description();
        Sign sign();
        void setSign(Sign sign);
        Byte at(int index);
        void setAt(int index, Byte value);
        long toLong();
    private:
        Sign s;
        std::shared_ptr<std::array<Byte, 5>> fields;
};


#endif

