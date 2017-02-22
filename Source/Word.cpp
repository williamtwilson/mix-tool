#include <iostream>
#include <sstream>
#include "Word.hpp"

Word::Word(): s(Sign::positive), fields(std::make_shared<std::array<Byte, 5>>()) {}

Word::Word(Sign sign, Byte a, Byte b, Byte c, Byte d, Byte e): s(sign), fields(std::make_shared<std::array<Byte, 5>>()) {
    s = sign;

    fields->at(0) = a;
    fields->at(1) = b;
    fields->at(2) = c;
    fields->at(3) = d;
    fields->at(4) = e;
}

Word::Word(long num): s(Sign::positive), fields(std::make_shared<std::array<Byte, 5>>()) {
    if (num < 0) {
        s = Sign::negative;
        num = 0 - num;
    }

    for (int i = 4; i >= 0; i--) {
        fields->at(i) = num % 64;
        num = num / 64;
    }
}

unsigned long Word::address() {
    return at(1) * 64 + at(2);
}

unsigned short Word::command() {
    return at(5);
}

std::string Word::description() {
    std::stringstream stream = std::stringstream();
    stream << signDescription(s);
    stream << " ";
    for (int i = 0; i < 5; i++) {
        if (i != 0) {
            stream << " ";
        }
        stream << std::to_string(fields->at(i));
    }
    return stream.str();
}

unsigned short Word::field() {
    return at(4);
}

unsigned short Word::index() {
    return at(3);
}

Sign Word::sign() {
    return s;
}

void Word::setSign(Sign sign) {
    s = sign;
}

Byte Word::at(int index) {
    return fields->at(index - 1);
}

void Word::setAt(int index, Byte value) {
    fields->at(index - 1) = value;
}

long Word::toLong() {
    long start = 0;
    start += at(5);
    start += at(4) * 64;
    start += at(3) * 64 * 64;
    start += at(2) * 64 * 64 * 64;
    start += at(1) * 64 * 64 * 64 * 64;

    Sign s = sign();
    if (s == Sign::negative) {
        start = 0 - start;
    }
    
    return start;
}

