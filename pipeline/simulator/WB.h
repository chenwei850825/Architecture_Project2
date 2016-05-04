
#ifndef WB_H
#define WB_H
#include"pipereg.h"

class WB
{
    string op;
    bitset<5>rs;
    bitset<5>rt;
    bitset<5>rd;
    int rsValue;
    int rtValue;
    int rdValue;
    bitset<5>shamt;
    bitset<16>immediate;
    bitset<26>address;
    int outCome;

public:
    WB();
    void exe();
};


#endif // WB_H
