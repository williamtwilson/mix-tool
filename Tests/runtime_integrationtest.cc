#include "gtest/gtest.h"
#include "headers.hpp"

class RuntimeTest: public testing::Test {
    protected:
        std::shared_ptr<Runtime> runtime;
        unsigned long secondByte;

        virtual void SetUp() {
            runtime = std::make_shared<Runtime>();
            secondByte = 64;
        }
};

TEST_F(RuntimeTest, Enters) {
    runtime->machine.memory.setAt(0, std::make_shared<Word>(Sign::positive, 1, 2, 0, 2, 48));
    runtime->executeNextCommand();
    EXPECT_EQ(runtime->machine.rA.description(), "+ 0 0 0 1 2");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)1);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)1);

    runtime->machine.memory.setAt(1, std::make_shared<Word>(Sign::positive, 2, 3, 0, 2, 49));
    runtime->executeNextCommand();
    EXPECT_EQ(runtime->machine.rI1.description(), "+ 0 0 0 2 3");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)2);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)2);

    runtime->machine.memory.setAt(2, std::make_shared<Word>(Sign::positive, 2, 3, 0, 2, 50));
    runtime->executeNextCommand();
    EXPECT_EQ(runtime->machine.rI2.description(), "+ 0 0 0 2 3");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)3);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)3);

    runtime->machine.memory.setAt(3, std::make_shared<Word>(Sign::positive, 2, 3, 0, 2, 51));
    runtime->executeNextCommand();
    EXPECT_EQ(runtime->machine.rI3.description(), "+ 0 0 0 2 3");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)4);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)4);

    runtime->machine.memory.setAt(4, std::make_shared<Word>(Sign::positive, 2, 3, 0, 2, 52));
    runtime->executeNextCommand();
    EXPECT_EQ(runtime->machine.rI4.description(), "+ 0 0 0 2 3");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)5);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)5);

    runtime->machine.memory.setAt(5, std::make_shared<Word>(Sign::positive, 2, 3, 0, 2, 53));
    runtime->executeNextCommand();
    EXPECT_EQ(runtime->machine.rI3.description(), "+ 0 0 0 2 3");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)6);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)6);

    runtime->machine.memory.setAt(6, std::make_shared<Word>(Sign::positive, 2, 3, 0, 2, 54));
    runtime->executeNextCommand();
    EXPECT_EQ(runtime->machine.rI3.description(), "+ 0 0 0 2 3");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)7);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)7);

    runtime->machine.memory.setAt(7, std::make_shared<Word>(Sign::positive, 2, 3, 0, 2, 55));
    runtime->executeNextCommand();
    EXPECT_EQ(runtime->machine.rI3.description(), "+ 0 0 0 2 3");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)8);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)8);
}

TEST_F(RuntimeTest, Jumps) {
    runtime->machine.memory.setAt(0, std::make_shared<Word>(Sign::positive, 0, 10, 0, 0, 39));
    runtime->machine.memory.setAt(10, std::make_shared<Word>(Sign::positive, 1, 2, 0, 2, 48));
    runtime->executeNextCommand();
    runtime->executeNextCommand();

    EXPECT_EQ(runtime->machine.rJ.description(), "+ 0 0 0 0 1");
    EXPECT_EQ(runtime->machine.rA.description(), "+ 0 0 0 1 2");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)2);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)11);

    runtime->machine.memory.setAt(11, std::make_shared<Word>(Sign::positive, 0, 20, 0, 1, 39));
    runtime->machine.memory.setAt(20, std::make_shared<Word>(Sign::positive, 3, 4, 0, 2, 48));
    runtime->executeNextCommand();
    runtime->executeNextCommand();

    EXPECT_EQ(runtime->machine.rJ.description(), "+ 0 0 0 0 1");
    EXPECT_EQ(runtime->machine.rA.description(), "+ 0 0 0 3 4");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)4);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)21);

    runtime->machine.memory.setAt(21, std::make_shared<Word>(Sign::positive, 0, 30, 0, 2, 39));
    runtime->executeNextCommand();

    EXPECT_EQ(runtime->machine.rJ.description(), "+ 0 0 0 0 1");
    EXPECT_EQ(runtime->machine.rA.description(), "+ 0 0 0 3 4");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)5);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)22);

    runtime->machine.overflowToggle = Overflow::on;
    runtime->machine.memory.setAt(22, std::make_shared<Word>(Sign::positive, 0, 30, 0, 2, 39));
    runtime->machine.memory.setAt(30, std::make_shared<Word>(Sign::positive, 5, 6, 0, 2, 48));
    runtime->executeNextCommand();
    runtime->executeNextCommand();

    EXPECT_EQ(runtime->machine.overflowToggle, Overflow::off);
    EXPECT_EQ(runtime->machine.rJ.description(), "+ 0 0 0 0 23");
    EXPECT_EQ(runtime->machine.rA.description(), "+ 0 0 0 5 6");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)7);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)31);

    runtime->machine.overflowToggle = Overflow::on;
    runtime->machine.memory.setAt(31, std::make_shared<Word>(Sign::positive, 0, 30, 0, 3, 39));
    runtime->executeNextCommand();

    EXPECT_EQ(runtime->machine.overflowToggle, Overflow::off);
    EXPECT_EQ(runtime->machine.rJ.description(), "+ 0 0 0 0 23");
    EXPECT_EQ(runtime->machine.rA.description(), "+ 0 0 0 5 6");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)8);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)32);

    runtime->machine.overflowToggle = Overflow::off;
    runtime->machine.memory.setAt(32, std::make_shared<Word>(Sign::positive, 0, 40, 0, 3, 39));
    runtime->machine.memory.setAt(40, std::make_shared<Word>(Sign::positive, 7, 8, 0, 2, 48));
    runtime->executeNextCommand();
    runtime->executeNextCommand();

    EXPECT_EQ(runtime->machine.overflowToggle, Overflow::off);
    EXPECT_EQ(runtime->machine.rJ.description(), "+ 0 0 0 0 33");
    EXPECT_EQ(runtime->machine.rA.description(), "+ 0 0 0 7 8");
    EXPECT_EQ(runtime->machine.totalCycles(), (unsigned long)10);
    EXPECT_EQ(runtime->machine.currentCommandAddress(), (unsigned long)41);
}

