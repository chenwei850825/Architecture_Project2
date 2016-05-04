
#ifndef DM_H
#define DM_H

#include"pipereg.h"

class DM
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
    int overflow;


public:
    DM();
    void exe();
};


#endif // DM_H
