#ifndef COMMAND_STORE_H
#define COMMAND_STORE_H

#include <utility>

#include "NoOperation.hpp"
#include "Add.hpp"
#include "Enter.hpp"
#include "Increment.hpp"
#include "Load.hpp"
#include "LoadNegative.hpp"
#include "Store.hpp"
#include "StoreZero.hpp"
#include "Jump.hpp"
#include "JumpSaveJ.hpp"
#include "JumpOnOverflow.hpp"
#include "JumpOnNoOverflow.hpp"
#include "Compare.hpp"

namespace CommandStore {
    extern std::shared_ptr<NoOperation> noOperation;
    extern std::shared_ptr<Add> add;

    extern std::string loadAName;
    extern std::shared_ptr<Load<9, 7> > loadA;
    extern std::string load1Name;
    extern std::shared_ptr<Load<9, 1> > load1;
    extern std::string load2Name;
    extern std::shared_ptr<Load<9, 2> > load2;
    extern std::string load3Name;
    extern std::shared_ptr<Load<9, 3> > load3;
    extern std::string load4Name;
    extern std::shared_ptr<Load<9, 4> > load4;
    extern std::string load5Name;
    extern std::shared_ptr<Load<9, 5> > load5;
    extern std::string load6Name;
    extern std::shared_ptr<Load<9, 6> > load6;
    extern std::string loadXName;
    extern std::shared_ptr<Load<9, 8> > loadX;

    extern std::string loadANegativeName;
    extern std::shared_ptr<LoadNegative<16, 7> > loadANegative;
    extern std::string load1NegativeName;
    extern std::shared_ptr<LoadNegative<16, 1> > load1Negative;
    extern std::string load2NegativeName;
    extern std::shared_ptr<LoadNegative<16, 2> > load2Negative;
    extern std::string load3NegativeName;
    extern std::shared_ptr<LoadNegative<16, 3> > load3Negative;
    extern std::string load4NegativeName;
    extern std::shared_ptr<LoadNegative<16, 4> > load4Negative;
    extern std::string load5NegativeName;
    extern std::shared_ptr<LoadNegative<16, 5> > load5Negative;
    extern std::string load6NegativeName;
    extern std::shared_ptr<LoadNegative<16, 6> > load6Negative;
    extern std::string loadXNegativeName;
    extern std::shared_ptr<LoadNegative<16, 8> > loadXNegative;

    extern std::string storeAName;
    extern std::shared_ptr<Store<25, 7> > storeA;
    extern std::string store1Name;
    extern std::shared_ptr<Store<25, 1> > store1;
    extern std::string store2Name;
    extern std::shared_ptr<Store<25, 2> > store2;
    extern std::string store3Name;
    extern std::shared_ptr<Store<25, 3> > store3;
    extern std::string store4Name;
    extern std::shared_ptr<Store<25, 4> >  store4;
    extern std::string store5Name;
    extern std::shared_ptr<Store<25, 5> > store5;
    extern std::string store6Name;
    extern std::shared_ptr<Store<25, 6> > store6;
    extern std::string storeXName;
    extern std::shared_ptr<Store<25, 8> > storeX;

    extern std::string storeJName;
    extern std::shared_ptr<Store<32, 9> > storeJ;
    extern std::shared_ptr<StoreZero> storeZero;
    extern std::shared_ptr<Jump> jump;
    extern std::shared_ptr<JumpSaveJ> jumpSaveJ;
    extern std::shared_ptr<JumpOnOverflow> jumpOnOverflow;
    extern std::shared_ptr<JumpOnNoOverflow> jumpOnNoOverflow;

    extern std::string enterAName;
    extern std::shared_ptr<Enter<48, 7> > enterA;
    extern std::string incrementAName;
    extern std::shared_ptr<Increment<48, 7> > incrementA;  
    extern std::string enter1Name;
    extern std::shared_ptr<Enter<48, 1> > enter1;
    extern std::string increment1Name;
    extern std::shared_ptr<Increment<48, 1>> increment1;
    extern std::string enter2Name;
    extern std::shared_ptr<Enter<48, 2> > enter2;
    extern std::string increment2Name;
    extern std::shared_ptr<Increment<48, 2> > increment2;
    extern std::string enter3Name;
    extern std::shared_ptr<Enter<48, 3> > enter3;
    extern std::string increment3Name;
    extern std::shared_ptr<Increment<48, 3> > increment3;
    extern std::string enter4Name;
    extern std::shared_ptr<Enter<48, 4> > enter4;
    extern std::string increment4Name;
    extern std::shared_ptr<Increment<48, 4> > increment4;
    extern std::string enter5Name;
    extern std::shared_ptr<Enter<48, 5> > enter5;
    extern std::string increment5Name;
    extern std::shared_ptr<Increment<48, 5> > increment5;
    extern std::string enter6Name;
    extern std::shared_ptr<Enter<48, 6> > enter6;
    extern std::string increment6Name;
    extern std::shared_ptr<Increment<48, 6> > increment6;
    extern std::string enterXName;
    extern std::shared_ptr<Enter<48, 8> > enterX;
    extern std::string incrementXName;
    extern std::shared_ptr<Increment<48, 8> > incrementX;

    extern std::string compareAName;
    extern std::shared_ptr<Compare<56, 7> > compareA;
    extern std::string compare1Name;
    extern std::shared_ptr<Compare<56, 1> > compare1;
    extern std::string compare2Name;
    extern std::shared_ptr<Compare<56, 2> > compare2;
    extern std::string compare3Name;
    extern std::shared_ptr<Compare<56, 3> > compare3;
    extern std::string compare4Name;
    extern std::shared_ptr<Compare<56, 4> > compare4;
    extern std::string compare5Name;
    extern std::shared_ptr<Compare<56, 5> > compare5;
    extern std::string compare6Name;
    extern std::shared_ptr<Compare<56, 6> > compare6;
    extern std::string compareXName;
    extern std::shared_ptr<Compare<56, 8> > compareX;

    extern std::shared_ptr<Command> lookupCommandByCode(unsigned short code, unsigned short field);
}

#endif

