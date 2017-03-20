#ifndef REGISTER_H
#define REGISTER_H

#include <memory>
#include <string>
#include "Word.hpp"

class Register {
public:
    Register();

    long contentsToLong();

    std::string description();
    void load(std::shared_ptr<Word> w);
    std::shared_ptr<Word> read();
private:
    std::shared_ptr<Word> word;
};

#endif

