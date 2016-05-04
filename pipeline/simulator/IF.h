
#ifndef IF_H
#define IF_H

#include<bitset>
#include"declaration.h"
#include"pipereg.h"
#include"constants.h"
using namespace std;

class IF
{

   bitset<32>instruciton;

    bitset<6>opcode;
    bitset<6>funct;
    bitset<5>rs;
    bitset<5>rt;
    bitset<5>rd;
    bitset<5>shamt;
    bitset<16>immediate;
    bitset<26>address;

public:

    IF();
    void R_type();
    void I_type();
    void J_type();
    void terminal_type();
    void exe();

};


#endif // ID_H
