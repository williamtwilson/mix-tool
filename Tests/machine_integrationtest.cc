#include "gtest/gtest.h"
#include "../headers.hpp"

std::shared_ptr<Machine> machine(std::make_shared<Machine>());
unsigned long secondByte = 64;
unsigned long thirdByte = 64 * 64;
unsigned long fourthByte = 64 * 64 * 64;
unsigned long fifthByte = 64 * 64 * 64 * 64;
unsigned long oneThroughFive = 1 + 2 * secondByte + 3 * thirdByte + 4 * fourthByte + 5 * fifthByte;

TEST(EnterA, CorrectValue) {
    CommandStore::enterA->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rA->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rA->description(), "+ 5 4 3 2 1");
}

