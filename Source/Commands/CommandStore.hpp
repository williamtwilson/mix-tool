#ifndef COMMAND_STORE_H
#define COMMAND_STORE_H

#include <utility>

#include "NoOperation.hpp"
#include "Add.hpp"

#include "EnterA.hpp"
#include "IncrementA.hpp"
#include "Enter1.hpp"
#include "Increment1.hpp"
#include "Enter2.hpp"
#include "Increment2.hpp"
#include "Enter3.hpp"
#include "Increment3.hpp"
#include "Enter4.hpp"
#include "Increment4.hpp"
#include "Enter5.hpp"
#include "Increment5.hpp"
#include "Enter6.hpp"
#include "Increment6.hpp"
#include "EnterX.hpp"
#include "IncrementX.hpp"

#include "LoadA.hpp"
#include "Load1.hpp"
#include "Load2.hpp"
#include "Load3.hpp"
#include "Load4.hpp"
#include "Load5.hpp"
#include "Load6.hpp"
#include "LoadX.hpp"

#include "LoadANegative.hpp"
#include "Load1Negative.hpp"
#include "Load2Negative.hpp"
#include "Load3Negative.hpp"
#include "Load4Negative.hpp"
#include "Load5Negative.hpp"
#include "Load6Negative.hpp"
#include "LoadXNegative.hpp"

#include "StoreA.hpp"
#include "Store1.hpp"
#include "Store2.hpp"
#include "Store3.hpp"
#include "Store4.hpp"
#include "Store5.hpp"
#include "Store6.hpp"
#include "StoreX.hpp"

#include "StoreJ.hpp"
#include "StoreZero.hpp"
#include "Jump.hpp"
#include "JumpSaveJ.hpp"
#include "JumpOnOverflow.hpp"
#include "JumpOnNoOverflow.hpp"

#include "CompareA.hpp"

namespace CommandStore {
    extern std::shared_ptr<NoOperation> noOperation;
    extern std::shared_ptr<Add> add;

    extern std::shared_ptr<LoadA> loadA;
    extern std::shared_ptr<Load1> load1;
    extern std::shared_ptr<Load2> load2;
    extern std::shared_ptr<Load3> load3;
    extern std::shared_ptr<Load4> load4;
    extern std::shared_ptr<Load5> load5;
    extern std::shared_ptr<Load6> load6;
    extern std::shared_ptr<LoadX> loadX;

    extern std::shared_ptr<LoadANegative> loadANegative;
    extern std::shared_ptr<Load1Negative> load1Negative;
    extern std::shared_ptr<Load2Negative> load2Negative;
    extern std::shared_ptr<Load3Negative> load3Negative;
    extern std::shared_ptr<Load4Negative> load4Negative;
    extern std::shared_ptr<Load5Negative> load5Negative;
    extern std::shared_ptr<Load6Negative> load6Negative;
    extern std::shared_ptr<LoadXNegative> loadXNegative;

    extern std::shared_ptr<StoreA> storeA;
    extern std::shared_ptr<Store1> store1;
    extern std::shared_ptr<Store2> store2;
    extern std::shared_ptr<Store3> store3;
    extern std::shared_ptr<Store4> store4;
    extern std::shared_ptr<Store5> store5;
    extern std::shared_ptr<Store6> store6;
    extern std::shared_ptr<StoreX> storeX;

    extern std::shared_ptr<StoreJ> storeJ;
    extern std::shared_ptr<StoreZero> storeZero;
    extern std::shared_ptr<Jump> jump;
    extern std::shared_ptr<JumpSaveJ> jumpSaveJ;
    extern std::shared_ptr<JumpOnOverflow> jumpOnOverflow;
    extern std::shared_ptr<JumpOnNoOverflow> jumpOnNoOverflow;

    extern std::shared_ptr<EnterA> enterA;
    extern std::shared_ptr<IncrementA> incrementA;
    extern std::shared_ptr<Enter1> enter1;
    extern std::shared_ptr<Increment1> increment1;
    extern std::shared_ptr<Enter2> enter2;
    extern std::shared_ptr<Increment2> increment2;
    extern std::shared_ptr<Enter3> enter3;
    extern std::shared_ptr<Increment3> increment3;
    extern std::shared_ptr<Enter4> enter4;
    extern std::shared_ptr<Increment4> increment4;
    extern std::shared_ptr<Enter5> enter5;
    extern std::shared_ptr<Increment5> increment5;
    extern std::shared_ptr<Enter6> enter6;
    extern std::shared_ptr<Increment6> increment6;
    extern std::shared_ptr<EnterX> enterX;
    extern std::shared_ptr<IncrementX> incrementX;

    extern std::shared_ptr<CompareA> compareA;

    extern std::shared_ptr<Command> lookupCommandByCode(unsigned short code, unsigned short field);
}

#endif

