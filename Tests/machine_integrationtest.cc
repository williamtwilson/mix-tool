#include "gtest/gtest.h"
#include "../headers.hpp"

class MachineTest: public testing::Test {
    protected:

    std::shared_ptr<Machine> machine;
    unsigned long secondByte;
    unsigned long thirdByte;
    unsigned long fourthByte;
    unsigned long fifthByte;
    unsigned long oneThroughFive;
    unsigned long negativeOneThroughFive;

    virtual void SetUp() {
        machine = std::make_shared<Machine>();
        secondByte = 64;
        thirdByte = 64 * 64;
        fourthByte = 64 * 64 * 64;
        fifthByte = 64 * 64 * 64 * 64;
        oneThroughFive = 1 + 2 * secondByte + 3 * thirdByte + 4 * fourthByte + 5 * fifthByte;
        negativeOneThroughFive = 0 - oneThroughFive;
    }

    virtual void fillZero() {
        CommandStore::enterA->execute(machine, negativeOneThroughFive, 0, 2);
        CommandStore::storeA->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
        CommandStore::enterA->execute(machine, 0, 0, 2);
    }
};

TEST_F(MachineTest, EnterA) {
    CommandStore::enterA->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rA->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rA->description(), "+ 5 4 3 2 1");
}

TEST_F(MachineTest, Enter1) {
    CommandStore::enter1->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI1->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI1->description(), "+ 5 4 3 2 1");
}

TEST_F(MachineTest, Enter2) {
    CommandStore::enter2->execute(machine, negativeOneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI2->contentsToLong(), negativeOneThroughFive);
    EXPECT_EQ(machine->rI2->description(), "- 5 4 3 2 1");
}

TEST_F(MachineTest, Enter3) {
    CommandStore::enter3->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI3->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI3->description(), "+ 5 4 3 2 1");
}

TEST_F(MachineTest, Enter4) {
    CommandStore::enter4->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI4->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI4->description(), "+ 5 4 3 2 1");
}

TEST_F(MachineTest, Enter5) {
    CommandStore::enter5->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI5->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI5->description(), "+ 5 4 3 2 1");
}

TEST_F(MachineTest, Enter6) {
    CommandStore::enter6->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI6->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI6->description(), "+ 5 4 3 2 1");
}

TEST_F(MachineTest, EnterX) {
    CommandStore::enterX->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rX->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rX->description(), "+ 5 4 3 2 1");
}

TEST_F(MachineTest, LoadA) {
    fillZero();
    CommandStore::loadA->execute(machine, 0000, 0, Command::fieldForIndexes(1, 2));
    EXPECT_EQ(machine->rA->description(), "+ 0 0 0 5 4");
}

TEST_F(MachineTest, Load1) {
    fillZero();
    CommandStore::load1->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI1->description(), "- 5 4 3 2 1");
}

TEST_F(MachineTest, Load2) {
    fillZero();
    CommandStore::load2->execute(machine, 0000, 0, Command::fieldForIndexes(3, 4));
    EXPECT_EQ(machine->rI2->description(), "+ 0 0 0 3 2");
}

TEST_F(MachineTest, Load3) {
    fillZero();
    CommandStore::load3->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI3->description(), "- 5 4 3 2 1");
}

TEST_F(MachineTest, Load4) {
    fillZero();
    CommandStore::load4->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI4->description(), "- 5 4 3 2 1");
}

TEST_F(MachineTest, Load5) {
    fillZero();
    CommandStore::load5->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI5->description(), "- 5 4 3 2 1");
}

TEST_F(MachineTest, Load6) {
    fillZero();
    CommandStore::load6->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI6->description(), "- 5 4 3 2 1");
}

TEST_F(MachineTest, LoadX) {
    fillZero();
    CommandStore::loadX->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rX->description(), "- 5 4 3 2 1");
}

TEST_F(MachineTest, StoreA) {
    CommandStore::enterA->execute(machine, negativeOneThroughFive, 0, 2);
    CommandStore::storeA->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->memory->at(0000)->description(), "- 5 4 3 2 1");
}

