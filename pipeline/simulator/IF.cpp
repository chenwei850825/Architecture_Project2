
#include "IF.h"

#include<iostream>
#include<iomanip>

IF::IF()
{
    pipereg::IF = declaration::iMemory[ declaration::PC >> 2 ];

}

void IF::exe()
{






    instruciton = pipereg::IF;
    string tmpForStall = pipereg::ID;
    pipereg::IF_ID_RegWrite = 0;



     int idx = 0;
    for( int i = 26; i <= 31; i++ )
    {
        opcode[idx] = instruciton[i];
        idx++;
    }


    //R-type
    if( opcode == 0x00 )
    {
        idx = 0;
        for( int i = 21; i <= 25; i++ )
        {
            rs[idx] = instruciton[i];
            idx++;
        }
        idx = 0;
        for( int i = 16; i <= 20; i++ )
        {
            rt[idx] = instruciton[i];
            idx++;
        }
        idx = 0;
        for( int i = 11; i <= 15; i++ )
        {
            rd[idx] = instruciton[i];
            idx++;
        }
        idx = 0;
        for( int i = 6; i <= 10 ; i++ )
        {
            shamt[idx] = instruciton[i];
            idx++;
        }
        idx = 0;
        for( int i = 0; i <= 5; i++ )
        {
            funct[idx] = instruciton[i];
            idx++;
        }


        R_type();

    }

    //J-type
    else if ( opcode == 0x02 || opcode == 0x03 )
    {
        idx = 0;
        for( int i = 0; i <= 25; i++ )
        {
            address[idx] = instruciton[i];
            idx++;
        }

        J_type();
    }

    //Terminal-type
    else if ( opcode == 0x3F )
    {
        idx = 0;
        for( int i = 0; i <= 25; i++ )
        {
            address[idx] = instruciton[i];
            idx++;
        }



        terminal_type();

    }

    //I-type
    else
    {
        idx = 0;
        for( int i = 21; i <= 25; i++ )
        {
            rs[idx] = instruciton[i];
            idx++;
        }
        idx = 0;
        for( int i = 16; i <= 20; i++ )
        {
            rt[idx] = instruciton[i];
            idx++;
        }
        idx = 0;
        for( int i = 0; i <= 15; i++ )
        {
            immediate[idx] = instruciton[i];
            idx++;
        }



        I_type();
    }



    if( pipereg::IF_Hazard == "STALLED" ){
        pipereg::ID = tmpForStall;
        pipereg::IF_Hazard = "NO_HAZARD";
        return;
    }

    else if ( pipereg::IF_Hazard == "FLUSHED" ){
        pipereg::ID = "NOP";
        pipereg::ID_Type = "NOP";
        pipereg::IF_Hazard = "NO_HAZARD";
        pipereg::IF = declaration::iMemory[ declaration::PC >> 2 ];
        return;
    }

    pipereg::IF_ID_rs = rs;
    pipereg::IF_ID_rt = rt;
    pipereg::IF_ID_rd = rd;
    pipereg::IF_ID_shamt = shamt;
    pipereg::IF_ID_immediate = immediate;
    pipereg::IF_ID_address = address;








    declaration::PC += 4;
    pipereg::IF = declaration::iMemory[ declaration::PC >> 2 ];


}


void IF::R_type()
{



    unsigned functNow = ( unsigned )( funct.to_ulong() );

    switch( functNow )
    {



    case ADD:

        pipereg::ID = "ADD";
        pipereg::IF_ID_RegWrite = 1;
        break;
    case ADDU:

        pipereg::ID = "ADDU";
        pipereg::IF_ID_RegWrite = 1;
        break;
    case SUB:

        pipereg::ID = "SUB";
        pipereg::IF_ID_RegWrite = 1;

        break;

    case AND:

        pipereg::ID = "AND";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case OR:

        pipereg::ID = "OR";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case XOR:

        pipereg::ID = "XOR";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case NOR:

        pipereg::ID = "NOR";
        pipereg::IF_ID_RegWrite = 1;

        break;

    case NAND:

        pipereg::ID = "NAND";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case SLT:

        pipereg::ID = "SLT";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case SLL:

        if( pipereg::IF == 0 ){
            pipereg::ID = "NOP";
            pipereg::ID_Type = "NOP";
            return;
        }
        else{
            pipereg::ID = "SLL";
            pipereg::IF_ID_RegWrite = 1;
        }



        break;

    case SRL:

        pipereg::ID = "SRL";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case SRA:

        pipereg::ID = "SRA";
        pipereg::IF_ID_RegWrite = 1;

        break;

    case JR:

        pipereg::ID = "JR";

        break;

    }
        pipereg::ID_Type = "R";

    declaration::halt = 0;
}
void IF::I_type()
{

    unsigned opcodeNow = ( unsigned )( opcode.to_ulong() );

    switch( opcodeNow )
    {
    case ADDI:

        pipereg::ID = "ADDI";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case ADDIU:

        pipereg::ID = "ADDIU";
        pipereg::IF_ID_RegWrite = 1;


        break;

    case LW:

        pipereg::ID = "LW";
        pipereg::IF_ID_RegWrite = 1;
        break;


    case LH:


        pipereg::ID = "LH";
        pipereg::IF_ID_RegWrite = 1;

        break;


    case LHU:


        pipereg::ID = "LHU";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case LB:


        pipereg::ID = "LB";
        pipereg::IF_ID_RegWrite = 1;
        break;


    case LBU:


        pipereg::ID = "LBU";
        pipereg::IF_ID_RegWrite = 1;
        break;


    case SW:

        pipereg::ID = "SW";
        break;


    case SH:

        pipereg::ID = "SH";

        break;


    case SB:


        pipereg::ID = "SB";
        break;


    case LUI:

        pipereg::ID = "LUI";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case ANDI:

        pipereg::ID = "ANDI";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case ORI:

        pipereg::ID = "ORI";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case NORI:

        pipereg::ID = "NORI";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case SLTI:

        pipereg::ID = "SLTI";
        pipereg::IF_ID_RegWrite = 1;
        break;

    case BEQ:

        pipereg::ID = "BEQ";

        break;

    case BNE:

        pipereg::ID = "BNE";

        break;

    case BGTZ:

        pipereg::ID = "BGTZ";

        break;

    }

    pipereg::ID_Type = "I";
    declaration::halt = 0;

}

void IF::J_type()
{

    unsigned opNow = ( unsigned ) ( opcode.to_ulong() ) ;
    switch( opNow )
    {
    case J :

        pipereg::ID = "J";

        break;

    case JAL :
        pipereg::ID = "JAL";

        break;
    }

    pipereg::ID_Type = "J";
    declaration::halt = 0;

}
void IF::terminal_type()
{
    pipereg::ID = "HALT";
    pipereg::ID_Type = "H";
    declaration::halt++;
}
