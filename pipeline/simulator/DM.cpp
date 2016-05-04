
#include "DM.h"
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


DM::DM()
{
    ;
}


void DM::exe()
{
    op = pipereg::MEM;
    rs = pipereg::EX_MEM_rs;
    rt = pipereg::EX_MEM_rt;
    rd = pipereg::EX_MEM_rd;
    rsValue = declaration::reg[ ( unsigned )( rs.to_ulong() ) ];
    rtValue = declaration::reg[ ( unsigned )( rt.to_ulong() ) ];
    rdValue = declaration::reg[ ( unsigned )( rd.to_ulong() ) ];
    pipereg::MEM_WB_rsValue = rsValue;
    pipereg::MEM_WB_rtValue = rtValue;
    pipereg::MEM_WB_rdValue = rdValue;
    shamt = pipereg::EX_MEM_shamt;
    immediate = pipereg::EX_MEM_immediate;
    address = pipereg::EX_MEM_address;
    outCome = pipereg::EX_MEM_outCome;



    int immediateSigned = bitset_to_long(immediate);


    if( op == "LW" ){

        overflow = rsValue + immediateSigned;

        if( overflow % 4 != 0 ){
            declaration::dataMisalign = 1;
            declaration::halt = 5;
        }

        overflow = rsValue + immediateSigned;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }
        overflow = rsValue + immediateSigned + 3;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }

        if( declaration::memoryOverflow == 1 || declaration::dataMisalign == 1 )
            return;


        int idx = 0;
        bitset<32> tmp;
        int idy = outCome;

        for( int i = 0; i < 32; i++ )
        {
            tmp[i] = declaration::dMemory[idy][idx];
            idx++;
            if( idx == 8 )
            {
                idx = 0;
                idy--;
            }
        }

        pipereg::MEM_WB_outCome =  (unsigned) ( tmp.to_ulong() );


    }


    else if ( op == "LH" ){

        overflow = rsValue + immediateSigned;
        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;

        if( overflow % 2 != 0 ){
            declaration::dataMisalign = 1;
            declaration::halt = 5;
        }

        overflow = rsValue + immediateSigned;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }
        overflow = rsValue + immediateSigned + 1;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }

        if( declaration::memoryOverflow == 1 || declaration::dataMisalign == 1 )
            return;



        int idx = 0;
        bitset<16> tmp;
        int idy = outCome;
        for( int i = 0; i < 16; i++ )
        {
            tmp[i] = declaration::dMemory[idy][idx];
            idx++;
            if( idx == 8 )
            {
                idx = 0;
                idy--;
            }
        }

        pipereg::MEM_WB_outCome = bitset_to_long(tmp);

    }

    else if ( op == "LHU" ){


         overflow = rsValue + immediateSigned;


        if( overflow % 2 != 0 ){
            declaration::dataMisalign = 1;
            declaration::halt = 5;
        }

        overflow = rsValue + immediateSigned;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }
        overflow = rsValue + immediateSigned + 1;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }

        if( declaration::memoryOverflow == 1 || declaration::dataMisalign == 1 )
            return;


        int idx = 0;
        bitset<16> tmp;
        int idy = outCome;
        for( int i = 0; i < 16; i++ )
        {
            tmp[i] = declaration::dMemory[idy][idx];
            idx++;
            if( idx == 8 )
            {
                idx = 0;
                idy--;
            }
        }

        pipereg::MEM_WB_outCome = (unsigned)( tmp.to_ulong() );
    }

    else if ( op == "LB" ){

         overflow = rsValue + immediateSigned;

        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }

        if( declaration::memoryOverflow == 1 )
            return;




        int idx = 0;
        bitset<8> tmp;
        int idy = outCome;
        for( int i = 0; i < 8; i++ )
        {
            tmp[i] = declaration::dMemory[idy][idx];
            idx++;
            if( idx == 8 )
            {
                idx = 0;
                idy--;
            }
        }
        pipereg::MEM_WB_outCome = bitset_to_long(tmp);
    }

    else if ( op == "LBU" ){

        overflow = rsValue + immediateSigned;


        if( overflow >= 1024 || overflow < 0){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }



        if(  declaration::memoryOverflow == 1 )
            return;



        int idx = 0;
        bitset<8> tmp;
        int idy = outCome;
        for( int i = 0; i < 8; i++ )
        {
            tmp[i] = declaration::dMemory[idy][idx];
            idx++;
            if( idx == 8 )
            {
                idx = 0;
                idy--;
            }
        }

        pipereg::MEM_WB_outCome = (unsigned)( tmp.to_ulong() );
    }

    else if ( op == "SW" ){

        overflow = rsValue + immediateSigned;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }
        overflow = rsValue + immediateSigned + 3;
        if( overflow >= 1024 || overflow < 0){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }
        overflow = rsValue + immediateSigned;
        if( overflow % 4 != 0 ){
            declaration::dataMisalign = 1;
            declaration::halt = 5;
        }

        if( declaration::memoryOverflow == 1 || declaration::dataMisalign == 1 )
            return;

        int idx = 0;
        bitset<32>tmp( rtValue );
        int idy = outCome;
        for( int i = 0; i < 32; i++ )
        {
            declaration::dMemory[idy][idx] = tmp[i];
            idx++;
            if( idx == 8 )
            {
                idx = 0;
                idy--;
            }
        }

        pipereg::MEM_WB_outCome = outCome;
    }

    else if ( op == "SH" ){

         overflow = rsValue + immediateSigned;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }
        overflow = rsValue + immediateSigned + 1;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }
        overflow = rsValue + immediateSigned;
        if( overflow % 2 != 0 ){
            declaration::dataMisalign = 1;
            declaration::halt = 5;
        }

        if( declaration::memoryOverflow == 1 || declaration::dataMisalign == 1 )
            return;


        int idx = 0;
        bitset<16>tmp( rtValue & 0x0000FFFF );
        int idy = outCome;
        for( int i = 0; i < 16; i++ )
        {
            declaration::dMemory[idy][idx] = tmp[i];
            idx++;
            if( idx == 8 )
            {
                idx = 0;
                idy--;
            }
        }

        pipereg::MEM_WB_outCome = outCome;
    }

    else if ( op == "SB" ){

        overflow = rsValue + immediateSigned;
        if( overflow >= 1024 || overflow < 0 ){
            declaration::memoryOverflow = 1;
            declaration::halt = 5;
        }


        if( declaration::memoryOverflow == 1 )
            return;



        int idx = 0;
        bitset<8>tmp( rtValue & 0x000000FF );
        int idy = outCome;
        for( int i = 0; i < 8; i++ )
        {
            declaration::dMemory[idy][idx] = tmp[i];
            idx++;
            if( idx == 8 )
            {
                idx = 0;
                idy--;
            }
        }

        pipereg::MEM_WB_outCome = outCome;

    }

    else{
        pipereg::MEM_WB_outCome = outCome;
    }


    pipereg::WB = op;
    pipereg::WB_Type = pipereg::MEM_Type;
    pipereg::MEM_WB_rs = rs;
    pipereg::MEM_WB_rt = rt;
    pipereg::MEM_WB_rd = rd;
    pipereg::MEM_WB_shamt = shamt;
    pipereg::MEM_WB_immediate = immediate;
    pipereg::MEM_WB_address = address;
    pipereg::MEM_WB_RegWrite = pipereg::ID_EX_RegWrite;

    return;

}
