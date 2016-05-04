
#ifndef ID_H
#define ID_H

#include"pipereg.h"
#include"constants.h"
#include<bitset>

using namespace std;

class ID
{


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




public:

    ID();
    void R_type();
    void I_type();
    void J_type();
    void terminal_type();
    void exe();

};

#endif // ID_H
