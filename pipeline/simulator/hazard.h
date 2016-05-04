
#ifndef HAZARD_H
#define HAZARD_H

#include"pipereg.h"
class hazard
{

    bitset<5>rs;
    bitset<5>rt;
    bitset<5>rd;
    int rsValue;
    int rtValue;
    int rdValue;



public:
    hazard();
    void exe();
    void branchForwarding();
    void branchStall();
    void nonBranchForwarding();
    void nonBranchStall();
    void flush();

};




#endif // HAZARD_H
