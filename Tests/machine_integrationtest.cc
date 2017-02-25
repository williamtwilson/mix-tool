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

TEST_F(MachineTest, NoOperation) {
    CommandStore::lookupCommandByCode(0, 0)->execute(machine, oneThroughFive, 0, 0);
    EXPECT_EQ(machine->rA->contentsToLong(), 0);
    EXPECT_EQ(machine->rA->description(), "+ 0 0 0 0 0");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Add1) {
    CommandStore::enterA->execute(machine, oneThroughFive, 0, 2);
    CommandStore::storeA->execute(machine, 0, 0, Command::fieldForIndexes(0,5));
    CommandStore::add->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rA->description(), "+ 10 8 6 4 2");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 5);
    EXPECT_EQ(machine->currentCommandAddress(), 3);
}

TEST_F(MachineTest, Add2) {
    CommandStore::enterA->execute(machine, oneThroughFive, 0, 2);
    CommandStore::storeA->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
    CommandStore::add->execute(machine, 0, 0, Command::fieldForIndexes(1, 2));
    EXPECT_EQ(machine->rA->description(), "+ 5 4 3 7 5");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 5);
    EXPECT_EQ(machine->currentCommandAddress(), 3);
}

TEST_F(MachineTest, Add3) {
    CommandStore::enterA->execute(machine, 63 * fifthByte, 0, 2);
    CommandStore::storeA->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
    CommandStore::enterA->execute(machine, oneThroughFive + (3 * fifthByte), 0, 2);
    CommandStore::add->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rA->description(), "+ 7 4 3 2 1");
    EXPECT_EQ(machine->overflowToggle, Overflow::on);
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Add4) {
    machine->memory->setAt(0, std::make_shared<Word>(negativeOneThroughFive));
    CommandStore::enterA->execute(machine, oneThroughFive, 0, 2);
    CommandStore::add->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rA->description(), "+ 0 0 0 0 0");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 3);
    EXPECT_EQ(machine->currentCommandAddress(), 2);
}


TEST_F(MachineTest, EnterA) {
    CommandStore::lookupCommandByCode(48, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rA->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rA->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Enter1) {
    CommandStore::lookupCommandByCode(49, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI1->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI1->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Enter2) {
    CommandStore::lookupCommandByCode(50, 2)->execute(machine, negativeOneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI2->contentsToLong(), negativeOneThroughFive);
    EXPECT_EQ(machine->rI2->description(), "- 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Enter3) {
    CommandStore::lookupCommandByCode(51, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI3->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI3->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Enter4) {
    CommandStore::lookupCommandByCode(52, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI4->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI4->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Enter5) {
    CommandStore::lookupCommandByCode(53, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI5->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI5->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Enter6) {
    CommandStore::lookupCommandByCode(54, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI6->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI6->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, EnterX) {
    CommandStore::lookupCommandByCode(55, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rX->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rX->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}


TEST_F(MachineTest, LoadA) {
    fillZero();
    CommandStore::lookupCommandByCode(8, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(1, 2));
    EXPECT_EQ(machine->rA->description(), "+ 0 0 0 5 4");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load1) {
    fillZero();
    CommandStore::lookupCommandByCode(9, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI1->description(), "- 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load2) {
    fillZero();
    CommandStore::lookupCommandByCode(10, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(3, 4));
    EXPECT_EQ(machine->rI2->description(), "+ 0 0 0 3 2");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load3) {
    fillZero();
    CommandStore::lookupCommandByCode(11, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI3->description(), "- 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load4) {
    fillZero();
    CommandStore::lookupCommandByCode(12, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI4->description(), "- 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load5) {
    fillZero();
    CommandStore::lookupCommandByCode(13, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI5->description(), "- 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load6) {
    fillZero();
    CommandStore::lookupCommandByCode(14, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI6->description(), "- 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, LoadX) {
    fillZero();
    CommandStore::lookupCommandByCode(15, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rX->description(), "- 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}


TEST_F(MachineTest, StoreA) {
    CommandStore::enterA->execute(machine, negativeOneThroughFive, 0, 2);
    CommandStore::lookupCommandByCode(24, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->memory->at(0000)->description(), "- 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 3);
    EXPECT_EQ(machine->currentCommandAddress(), 2);
}

TEST_F(MachineTest, Store1) {
    CommandStore::enter1->execute(machine, negativeOneThroughFive, 0, 2);
    CommandStore::lookupCommandByCode(25, 0)->execute(machine, 0001, 0, Command::fieldForIndexes(1, 3));
    EXPECT_EQ(machine->memory->at(0001)->description(), "+ 3 2 1 0 0");
    EXPECT_EQ(machine->totalCycles(), 3);
    EXPECT_EQ(machine->currentCommandAddress(), 2);
}

TEST_F(MachineTest, Store2) {
    CommandStore::enter2->execute(machine, negativeOneThroughFive, 0, 2);
    CommandStore::lookupCommandByCode(26, 0)->execute(machine, 0002, 0, Command::fieldForIndexes(2, 3));
    EXPECT_EQ(machine->memory->at(0002)->description(), "+ 0 2 1 0 0");
    EXPECT_EQ(machine->totalCycles(), 3);
    EXPECT_EQ(machine->currentCommandAddress(), 2);
}

TEST_F(MachineTest, Store3) {
    CommandStore::enter3->execute(machine, negativeOneThroughFive, 0, 2);
    CommandStore::lookupCommandByCode(27, 0)->execute(machine, 0003, 0, Command::fieldForIndexes(3, 3));
    EXPECT_EQ(machine->memory->at(0003)->description(), "+ 0 0 1 0 0");
    EXPECT_EQ(machine->totalCycles(), 3);
    EXPECT_EQ(machine->currentCommandAddress(), 2);
}

TEST_F(MachineTest, Store4) {
    CommandStore::enter4->execute(machine, negativeOneThroughFive, 0, 2);
    CommandStore::lookupCommandByCode(28, 0)->execute(machine, 0004, 0, Command::fieldForIndexes(1, 3));
    EXPECT_EQ(machine->memory->at(0004)->description(), "+ 3 2 1 0 0");
    EXPECT_EQ(machine->totalCycles(), 3);
    EXPECT_EQ(machine->currentCommandAddress(), 2);
}

TEST_F(MachineTest, Store5) {
    CommandStore::enter5->execute(machine, negativeOneThroughFive, 0, 2);
    CommandStore::lookupCommandByCode(29, 0)->execute(machine, 0005, 0, Command::fieldForIndexes(1, 3));
    EXPECT_EQ(machine->memory->at(0005)->description(), "+ 3 2 1 0 0");
    EXPECT_EQ(machine->totalCycles(), 3);
    EXPECT_EQ(machine->currentCommandAddress(), 2);
}

TEST_F(MachineTest, Store6) {
    CommandStore::enter6->execute(machine, negativeOneThroughFive, 0, 2);
    CommandStore::lookupCommandByCode(30, 0)->execute(machine, 0006, 0, Command::fieldForIndexes(1, 3));
    EXPECT_EQ(machine->memory->at(0006)->description(), "+ 3 2 1 0 0");
    EXPECT_EQ(machine->totalCycles(), 3);
    EXPECT_EQ(machine->currentCommandAddress(), 2);
}

TEST_F(MachineTest, StoreX) {
    CommandStore::enterX->execute(machine, negativeOneThroughFive, 0, 2);
    CommandStore::lookupCommandByCode(31, 0)->execute(machine, 0001, 0, Command::fieldForIndexes(1, 3));
    EXPECT_EQ(machine->memory->at(0001)->description(), "+ 3 2 1 0 0");
    EXPECT_EQ(machine->totalCycles(), 3);
    EXPECT_EQ(machine->currentCommandAddress(), 2);
}

