#include "gtest/gtest.h"
#include "headers.hpp"

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

TEST_F(MachineTest, IncrementA) {
    CommandStore::lookupCommandByCode(48, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rA->contentsToLong(), oneThroughFive);
    CommandStore::lookupCommandByCode(48, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->rA->contentsToLong(), oneThroughFive + 10);
    EXPECT_EQ(machine->rA->description(), "+ 5 4 3 2 11");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 2);
    EXPECT_EQ(machine->currentCommandAddress(), 2);

    CommandStore::enterA->execute(machine, 63 * fifthByte + 63 * fourthByte + 63 * thirdByte + 63 * secondByte + 63, 0, 2);
    CommandStore::lookupCommandByCode(48, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->overflowToggle, Overflow::on);
    EXPECT_EQ(machine->rA->description(), "+ 0 0 0 0 9");
    EXPECT_EQ(machine->totalCycles(), 4);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Enter1) {
    CommandStore::lookupCommandByCode(49, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI1->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI1->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Increment1) {
    CommandStore::lookupCommandByCode(49, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI1->contentsToLong(), oneThroughFive);
    CommandStore::lookupCommandByCode(49, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->rI1->contentsToLong(), oneThroughFive + 10);
    EXPECT_EQ(machine->rI1->description(), "+ 5 4 3 2 11");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 2);
    EXPECT_EQ(machine->currentCommandAddress(), 2);

    CommandStore::enter1->execute(machine, 63 * fifthByte + 63 * fourthByte + 63 * thirdByte + 63 * secondByte + 63, 0, 2);
    CommandStore::lookupCommandByCode(49, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->overflowToggle, Overflow::on);
    EXPECT_EQ(machine->rI1->description(), "+ 0 0 0 0 9");
    EXPECT_EQ(machine->totalCycles(), 4);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Enter2) {
    CommandStore::lookupCommandByCode(50, 2)->execute(machine, negativeOneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI2->contentsToLong(), negativeOneThroughFive);
    EXPECT_EQ(machine->rI2->description(), "- 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Increment2) {
    CommandStore::lookupCommandByCode(50, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI2->contentsToLong(), oneThroughFive);
    CommandStore::lookupCommandByCode(50, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->rI2->contentsToLong(), oneThroughFive + 10);
    EXPECT_EQ(machine->rI2->description(), "+ 5 4 3 2 11");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 2);
    EXPECT_EQ(machine->currentCommandAddress(), 2);

    CommandStore::enter2->execute(machine, 63 * fifthByte + 63 * fourthByte + 63 * thirdByte + 63 * secondByte + 63, 0, 2);
    CommandStore::lookupCommandByCode(50, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->overflowToggle, Overflow::on);
    EXPECT_EQ(machine->rI2->description(), "+ 0 0 0 0 9");
    EXPECT_EQ(machine->totalCycles(), 4);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Enter3) {
    CommandStore::lookupCommandByCode(51, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI3->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI3->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Increment3) {
    CommandStore::lookupCommandByCode(51, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI3->contentsToLong(), oneThroughFive);
    CommandStore::lookupCommandByCode(51, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->rI3->contentsToLong(), oneThroughFive + 10);
    EXPECT_EQ(machine->rI3->description(), "+ 5 4 3 2 11");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 2);
    EXPECT_EQ(machine->currentCommandAddress(), 2);

    CommandStore::enter3->execute(machine, 63 * fifthByte + 63 * fourthByte + 63 * thirdByte + 63 * secondByte + 63, 0, 3);
    CommandStore::lookupCommandByCode(51, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->overflowToggle, Overflow::on);
    EXPECT_EQ(machine->rI3->description(), "+ 0 0 0 0 9");
    EXPECT_EQ(machine->totalCycles(), 4);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Enter4) {
    CommandStore::lookupCommandByCode(52, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI4->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI4->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Increment4) {
    CommandStore::lookupCommandByCode(52, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI4->contentsToLong(), oneThroughFive);
    CommandStore::lookupCommandByCode(52, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->rI4->contentsToLong(), oneThroughFive + 10);
    EXPECT_EQ(machine->rI4->description(), "+ 5 4 3 2 11");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 2);
    EXPECT_EQ(machine->currentCommandAddress(), 2);

    CommandStore::enter4->execute(machine, 63 * fifthByte + 63 * fourthByte + 63 * thirdByte + 63 * secondByte + 63, 0, 3);
    CommandStore::lookupCommandByCode(52, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->overflowToggle, Overflow::on);
    EXPECT_EQ(machine->rI4->description(), "+ 0 0 0 0 9");
    EXPECT_EQ(machine->totalCycles(), 4);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Enter5) {
    CommandStore::lookupCommandByCode(53, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI5->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI5->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Increment5) {
    CommandStore::lookupCommandByCode(53, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI5->contentsToLong(), oneThroughFive);
    CommandStore::lookupCommandByCode(53, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->rI5->contentsToLong(), oneThroughFive + 10);
    EXPECT_EQ(machine->rI5->description(), "+ 5 4 3 2 11");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 2);
    EXPECT_EQ(machine->currentCommandAddress(), 2);

    CommandStore::enter5->execute(machine, 63 * fifthByte + 63 * fourthByte + 63 * thirdByte + 63 * secondByte + 63, 0, 3);
    CommandStore::lookupCommandByCode(53, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->overflowToggle, Overflow::on);
    EXPECT_EQ(machine->rI5->description(), "+ 0 0 0 0 9");
    EXPECT_EQ(machine->totalCycles(), 4);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Enter6) {
    CommandStore::lookupCommandByCode(54, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI6->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rI6->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, Increment6) {
    CommandStore::lookupCommandByCode(54, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rI6->contentsToLong(), oneThroughFive);
    CommandStore::lookupCommandByCode(54, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->rI6->contentsToLong(), oneThroughFive + 10);
    EXPECT_EQ(machine->rI6->description(), "+ 5 4 3 2 11");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 2);
    EXPECT_EQ(machine->currentCommandAddress(), 2);

    CommandStore::enter6->execute(machine, 63 * fifthByte + 63 * fourthByte + 63 * thirdByte + 63 * secondByte + 63, 0, 3);
    CommandStore::lookupCommandByCode(54, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->overflowToggle, Overflow::on);
    EXPECT_EQ(machine->rI6->description(), "+ 0 0 0 0 9");
    EXPECT_EQ(machine->totalCycles(), 4);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, EnterX) {
    CommandStore::lookupCommandByCode(55, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rX->contentsToLong(), oneThroughFive);
    EXPECT_EQ(machine->rX->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 1);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, IncrementX) {
    CommandStore::lookupCommandByCode(55, 2)->execute(machine, oneThroughFive, 0, 2);
    EXPECT_EQ(machine->rX->contentsToLong(), oneThroughFive);
    CommandStore::lookupCommandByCode(55, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->rX->contentsToLong(), oneThroughFive + 10);
    EXPECT_EQ(machine->rX->description(), "+ 5 4 3 2 11");
    EXPECT_EQ(machine->overflowToggle, Overflow::off);
    EXPECT_EQ(machine->totalCycles(), 2);
    EXPECT_EQ(machine->currentCommandAddress(), 2);

    CommandStore::enterX->execute(machine, 63 * fifthByte + 63 * fourthByte + 63 * thirdByte + 63 * secondByte + 63, 0, 3);
    CommandStore::lookupCommandByCode(55, 0)->execute(machine, 10, 0, 0);
    EXPECT_EQ(machine->overflowToggle, Overflow::on);
    EXPECT_EQ(machine->rX->description(), "+ 0 0 0 0 9");
    EXPECT_EQ(machine->totalCycles(), 4);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
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


TEST_F(MachineTest, LoadANegative) {
    fillZero();
    CommandStore::lookupCommandByCode(16, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rA->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load1Negative) {
    fillZero();
    CommandStore::lookupCommandByCode(17, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI1->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load2Negative) {
    fillZero();
    CommandStore::lookupCommandByCode(18, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI2->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load3Negative) {
    fillZero();
    CommandStore::lookupCommandByCode(19, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI3->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load4Negative) {
    fillZero();
    CommandStore::lookupCommandByCode(20, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI4->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load5Negative) {
    fillZero();
    CommandStore::lookupCommandByCode(21, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI5->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, Load6Negative) {
    fillZero();
    CommandStore::lookupCommandByCode(22, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rI6->description(), "+ 5 4 3 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, LoadXNegative) {
    fillZero();
    CommandStore::lookupCommandByCode(23, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(0, 5));
    EXPECT_EQ(machine->rX->description(), "+ 5 4 3 2 1");
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


TEST_F(MachineTest, StoreJ) {
    Word negOneThroughFiveWord = Word(negativeOneThroughFive);
    machine->rJ->load(negOneThroughFiveWord);
    CommandStore::lookupCommandByCode(32, 0)->execute(machine, 0001, 0, Command::fieldForIndexes(1, 3));
    EXPECT_EQ(machine->memory->at(0001)->description(), "+ 3 2 1 0 0");
    EXPECT_EQ(machine->totalCycles(), 2);
    EXPECT_EQ(machine->currentCommandAddress(), 1);
}

TEST_F(MachineTest, StoreZero) {
    fillZero();
    CommandStore::lookupCommandByCode(33, 0)->execute(machine, 0000, 0, Command::fieldForIndexes(1, 3));
    EXPECT_EQ(machine->memory->at(0000)->description(), "- 0 0 0 2 1");
    EXPECT_EQ(machine->totalCycles(), 6);
    EXPECT_EQ(machine->currentCommandAddress(), 4);
}

TEST_F(MachineTest, CompareA) {
     machine->memory->setAt(0, std::make_shared<Word>(1000));
     CommandStore::enterA->execute(machine, 1001, 0, 2);
     CommandStore::lookupCommandByCode(56, Command::fieldForIndexes(0,5))->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);
     EXPECT_EQ(machine->totalCycles(), 3);
     EXPECT_EQ(machine->currentCommandAddress(), 2);

     CommandStore::enterA->execute(machine, 999, 0, 2);
     CommandStore::compareA->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);

     CommandStore::enterA->execute(machine, 1000, 0, 2);
     CommandStore::compareA->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::equal);

     machine->memory->setAt(0, std::make_shared<Word>(4034)); // 64 * 63 + 2
     CommandStore::enterA->execute(machine, 5, 0, 2);
     CommandStore::compareA->execute(machine, 0, 0, Command::fieldForIndexes(4, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
     CommandStore::compareA->execute(machine, 0, 0, Command::fieldForIndexes(5, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);

     machine->memory->setAt(0, std::make_shared<Word>(0));
     CommandStore::enterA->execute(machine, -63, 0, 0);
     CommandStore::compareA->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
}

TEST_F(MachineTest, Compare1) {
     machine->memory->setAt(0, std::make_shared<Word>(1000));
     CommandStore::enter1->execute(machine, 1001, 0, 2);
     CommandStore::lookupCommandByCode(57, Command::fieldForIndexes(0,5))->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);
     EXPECT_EQ(machine->totalCycles(), 3);
     EXPECT_EQ(machine->currentCommandAddress(), 2);

     CommandStore::enter1->execute(machine, 999, 0, 2);
     CommandStore::compare1->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);

     CommandStore::enter1->execute(machine, 1000, 0, 2);
     CommandStore::compare1->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::equal);

     machine->memory->setAt(0, std::make_shared<Word>(4034)); // 64 * 63 + 2
     CommandStore::enter1->execute(machine, 5, 0, 2);
     CommandStore::compare1->execute(machine, 0, 0, Command::fieldForIndexes(4, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
     CommandStore::compare1->execute(machine, 0, 0, Command::fieldForIndexes(5, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);

     machine->memory->setAt(0, std::make_shared<Word>(0));
     CommandStore::enter1->execute(machine, -63, 0, 0);
     CommandStore::compare1->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
}

TEST_F(MachineTest, Compare2) {
     machine->memory->setAt(0, std::make_shared<Word>(1000));
     CommandStore::enter2->execute(machine, 1001, 0, 2);
     CommandStore::lookupCommandByCode(58, Command::fieldForIndexes(0,5))->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);
     EXPECT_EQ(machine->totalCycles(), 3);
     EXPECT_EQ(machine->currentCommandAddress(), 2);

     CommandStore::enter2->execute(machine, 999, 0, 2);
     CommandStore::compare2->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);

     CommandStore::enter2->execute(machine, 1000, 0, 2);
     CommandStore::compare2->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::equal);

     machine->memory->setAt(0, std::make_shared<Word>(4034)); // 64 * 63 + 2
     CommandStore::enter2->execute(machine, 5, 0, 2);
     CommandStore::compare2->execute(machine, 0, 0, Command::fieldForIndexes(4, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
     CommandStore::compare2->execute(machine, 0, 0, Command::fieldForIndexes(5, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);

     machine->memory->setAt(0, std::make_shared<Word>(0));
     CommandStore::enter2->execute(machine, -63, 0, 0);
     CommandStore::compare2->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
}

TEST_F(MachineTest, Compare3) {
     machine->memory->setAt(0, std::make_shared<Word>(1000));
     CommandStore::enter3->execute(machine, 1001, 0, 2);
     CommandStore::lookupCommandByCode(59, Command::fieldForIndexes(0,5))->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);
     EXPECT_EQ(machine->totalCycles(), 3);
     EXPECT_EQ(machine->currentCommandAddress(), 2);

     CommandStore::enter3->execute(machine, 999, 0, 2);
     CommandStore::compare3->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);

     CommandStore::enter3->execute(machine, 1000, 0, 2);
     CommandStore::compare3->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::equal);

     machine->memory->setAt(0, std::make_shared<Word>(4034)); // 64 * 63 + 2
     CommandStore::enter3->execute(machine, 5, 0, 2);
     CommandStore::compare3->execute(machine, 0, 0, Command::fieldForIndexes(4, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
     CommandStore::compare3->execute(machine, 0, 0, Command::fieldForIndexes(5, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);

     machine->memory->setAt(0, std::make_shared<Word>(0));
     CommandStore::enter3->execute(machine, -63, 0, 0);
     CommandStore::compare3->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
}

TEST_F(MachineTest, Compare4) {
     machine->memory->setAt(0, std::make_shared<Word>(1000));
     CommandStore::enter4->execute(machine, 1001, 0, 2);
     CommandStore::lookupCommandByCode(60, Command::fieldForIndexes(0,5))->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);
     EXPECT_EQ(machine->totalCycles(), 3);
     EXPECT_EQ(machine->currentCommandAddress(), 2);

     CommandStore::enter4->execute(machine, 999, 0, 2);
     CommandStore::compare4->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);

     CommandStore::enter4->execute(machine, 1000, 0, 2);
     CommandStore::compare4->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::equal);

     machine->memory->setAt(0, std::make_shared<Word>(4034)); // 64 * 63 + 2
     CommandStore::enter4->execute(machine, 5, 0, 2);
     CommandStore::compare4->execute(machine, 0, 0, Command::fieldForIndexes(4, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
     CommandStore::compare4->execute(machine, 0, 0, Command::fieldForIndexes(5, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);

     machine->memory->setAt(0, std::make_shared<Word>(0));
     CommandStore::enter4->execute(machine, -63, 0, 0);
     CommandStore::compare4->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
}

TEST_F(MachineTest, Compare5) {
     machine->memory->setAt(0, std::make_shared<Word>(1000));
     CommandStore::enter5->execute(machine, 1001, 0, 2);
     CommandStore::lookupCommandByCode(61, Command::fieldForIndexes(0,5))->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);
     EXPECT_EQ(machine->totalCycles(), 3);
     EXPECT_EQ(machine->currentCommandAddress(), 2);

     CommandStore::enter5->execute(machine, 999, 0, 2);
     CommandStore::compare5->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);

     CommandStore::enter5->execute(machine, 1000, 0, 2);
     CommandStore::compare5->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::equal);

     machine->memory->setAt(0, std::make_shared<Word>(4034)); // 64 * 63 + 2
     CommandStore::enter5->execute(machine, 5, 0, 2);
     CommandStore::compare5->execute(machine, 0, 0, Command::fieldForIndexes(4, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
     CommandStore::compare5->execute(machine, 0, 0, Command::fieldForIndexes(5, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);

     machine->memory->setAt(0, std::make_shared<Word>(0));
     CommandStore::enter5->execute(machine, -63, 0, 0);
     CommandStore::compare5->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
}

TEST_F(MachineTest, Compare6) {
     machine->memory->setAt(0, std::make_shared<Word>(1000));
     CommandStore::enter6->execute(machine, 1001, 0, 2);
     CommandStore::lookupCommandByCode(62, Command::fieldForIndexes(0,5))->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);
     EXPECT_EQ(machine->totalCycles(), 3);
     EXPECT_EQ(machine->currentCommandAddress(), 2);

     CommandStore::enter6->execute(machine, 999, 0, 2);
     CommandStore::compare6->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);

     CommandStore::enter6->execute(machine, 1000, 0, 2);
     CommandStore::compare6->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::equal);

     machine->memory->setAt(0, std::make_shared<Word>(4034)); // 64 * 63 + 2
     CommandStore::enter6->execute(machine, 5, 0, 2);
     CommandStore::compare6->execute(machine, 0, 0, Command::fieldForIndexes(4, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
     CommandStore::compare6->execute(machine, 0, 0, Command::fieldForIndexes(5, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);

     machine->memory->setAt(0, std::make_shared<Word>(0));
     CommandStore::enter6->execute(machine, -63, 0, 0);
     CommandStore::compare6->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
}

TEST_F(MachineTest, CompareX) {
     machine->memory->setAt(0, std::make_shared<Word>(1000));
     CommandStore::enterX->execute(machine, 1001, 0, 2);
     CommandStore::lookupCommandByCode(63, Command::fieldForIndexes(0,5))->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);
     EXPECT_EQ(machine->totalCycles(), 3);
     EXPECT_EQ(machine->currentCommandAddress(), 2);

     CommandStore::enterX->execute(machine, 999, 0, 2);
     CommandStore::compareX->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);

     CommandStore::enterX->execute(machine, 1000, 0, 2);
     CommandStore::compareX->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::equal);

     machine->memory->setAt(0, std::make_shared<Word>(4034)); // 64 * 63 + 2
     CommandStore::enterX->execute(machine, 5, 0, 2);
     CommandStore::compareX->execute(machine, 0, 0, Command::fieldForIndexes(4, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
     CommandStore::compareX->execute(machine, 0, 0, Command::fieldForIndexes(5, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::greater);

     machine->memory->setAt(0, std::make_shared<Word>(0));
     CommandStore::enterX->execute(machine, -63, 0, 0);
     CommandStore::compareX->execute(machine, 0, 0, Command::fieldForIndexes(0, 5));
     EXPECT_EQ(machine->comparisonIndicator, Comparison::less);
}
