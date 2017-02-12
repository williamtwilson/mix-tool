#include <memory>
#include <string>
#include "Word.hpp"

#ifndef REGISTER_H
#define REGISTER_H

class Register {
    public:
        Register();

        long contentsToLong();

        std::string description();
        void load(Word *w);
        std::shared_ptr<Word> read();
    private:
        std::shared_ptr<Word> word;
};

#endif

