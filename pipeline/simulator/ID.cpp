
#include"ID.h"
#include<iostream>
using namespace std;

template<std::size_t B>
long bitset_to_long(const std::bitset<B>& b)
{
    struct
    {
long x:
        B;
    } s;
    return s.x = b.to_ulong();
}

ID::ID()
{
    ;
}


void ID::exe()
{


    op = pipereg::ID;
    op_type = pipereg::ID_Type;
    rs = pipereg::IF_ID_rs;
    rt = pipereg::IF_ID_rt;
    rd = pipereg::IF_ID_rd;
    if( pipereg::ID_Hazard[1] == 'F' ){

        if( pipereg::ID_Hazard[0] == 's' ){
            rsValue = pipereg::EX_MEM_outCome;
            rtValue = declaration::reg[ ( unsigned )( rt.to_ulong() ) ];
        }
        else{
            rsValue = declaration::reg[ ( unsigned )( rs.to_ulong() ) ];
            rtValue = pipereg::EX_MEM_outCome;
        }
        pipereg::ID_Hazard = "NO_HAZARD";

    }
    else{
        rsValue = declaration::reg[ ( unsigned )( rs.to_ulong() ) ];
        rtValue = declaration::reg[ ( unsigned )( rt.to_ulong() ) ];
    }
    rdValue = declaration::reg[ ( unsigned )( rd.to_ulong() ) ];
    pipereg::IF_ID_rsValue = rsValue;
    pipereg::IF_ID_rtValue = rtValue;
    pipereg::IF_ID_rdValue = rdValue;
    shamt = pipereg::IF_ID_shamt;
    immediate = pipereg::IF_ID_immediate;
    address = pipereg::IF_ID_address;
    pipereg::ID_EX_RegWrite = 0;



    int immediateSigned = bitset_to_long(immediate);
    unsigned addressNow = ( unsigned )  ( address.to_ulong() ) ;

    if( pipereg::ID_Hazard == "STALLED" ) {
        pipereg::EX = "NOP";
        pipereg::EX_Type = "NOP";
        pipereg::ID_Hazard = "NO_HAZARD";
        return;
    }

    if( op == "JR" ){
        declaration::PC = rsValue;
    }
    else if ( op == "BEQ" ){
        if( rtValue == rsValue )
            declaration::PC = declaration::PC  + 4 * immediateSigned;
    }
    else if ( pipereg::ID == "BNE" ){
        if( rtValue != rsValue )
            declaration::PC = declaration::PC + 4 * immediateSigned;
    }

    else if ( pipereg::ID == "BGTZ" ){
        if( rsValue > 0 )
            declaration::PC = declaration::PC  + 4 * immediateSigned;
    }
    else if ( pipereg::ID == "J" ){
        declaration::PC = ( ( declaration::PC  ) >> 28 << 28 ) | ( 4 * addressNow );
    }

    else if ( pipereg::ID == "JAL" ){
        declaration::reg[31] = declaration::PC ;
        declaration::PC = ( ( declaration::PC  ) >> 28 << 28 ) | ( 4 * addressNow );

    }











    pipereg::EX = op;
    pipereg::EX_Type = op_type;
    pipereg::ID_EX_rs = rs;
    pipereg::ID_EX_rt = rt;
    pipereg::ID_EX_rd = rd;

    pipereg::ID_EX_shamt = shamt;
    pipereg::ID_EX_immediate = immediate;
    pipereg::ID_EX_address = address;
    pipereg::ID_EX_RegWrite = pipereg::IF_ID_RegWrite;


    return;



}


