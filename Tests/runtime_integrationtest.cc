#include "gtest/gtest.h"
#include "../headers.hpp"

class RuntimeTest: public testing::Test {
    protected:
        std::shared_ptr<Runtime> runtime;
        unsigned long secondByte;

        virtual void SetUp() {
            runtime = std::make_shared<Runtime>();
            secondByte = 64;
        }
};

TEST_F(RuntimeTest, EnterA) {
    std::shared_ptr<Word> enterAWord = std::make_shared<Word>(Sign::positive, 1, 2, 0, 2, 48);
    runtime->executeWord(enterAWord);
    EXPECT_EQ(runtime->machine->rA->description(), "+ 0 0 0 1 2");
    EXPECT_EQ(runtime->machine->totalCycles(), 1);
    EXPECT_EQ(runtime->machine->currentCommandAddress(), 1);
}
