#ifndef EX_H
#define EX_H

#include<bitset>
#include"pipereg.h"
using namespace std;

class EX
{

    int overflow;
    string op;
    string op_type;
    bitset<5>rs;
    bitset<5>rt;
    bitset<5>rd;
    bitset<5>shamt;
    bitset<16>immediate;
    bitset<26>address;
    int rsValue;
    int rtValue;
    int rdValue;
    int outCome;


public:

    EX();
    void exe();

};


#endif // EX_H
