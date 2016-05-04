
#include"WB.h"
#include<iostream>
using namespace std;


WB::WB()
{
    ;
}

void WB::exe()
{



    op = pipereg::WB;
    rs = pipereg::MEM_WB_rs;
    rt = pipereg::MEM_WB_rt;
    rd = pipereg::MEM_WB_rd;
    rsValue = declaration::reg[ ( unsigned )( rs.to_ulong() ) ];
    rtValue = declaration::reg[ ( unsigned )( rt.to_ulong() ) ];
    rdValue = declaration::reg[ ( unsigned )( rd.to_ulong() ) ];
    shamt = pipereg::MEM_WB_shamt;
    immediate = pipereg::MEM_WB_immediate;
    address = pipereg::MEM_WB_address;
    outCome = pipereg::MEM_WB_outCome;



    unsigned rtNow = ( unsigned )( rt.to_ulong() );
    unsigned rdNow = ( unsigned )( rd.to_ulong() );


    declaration::cycle++;


      if( op == "ADD" ) {

        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rdNow] = outCome;

    }
    else if( op == "ADDU" ){

        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rdNow] = outCome;

    }
    else if( op == "SUB" ){

        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rdNow] = outCome;

    }


    else if( op == "AND" ){


        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

       declaration::reg[rdNow] = outCome;

    }
    else if( op == "OR" ){



        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

       declaration::reg[rdNow] = outCome;

    }
    else if( op == "XOR" ){


        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rdNow] = outCome;

    }
    else if( op == "NOR" ){


        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rdNow] = outCome;

    }
    else if( op == "NAND" ){

        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rdNow] = outCome;

    }
    else if( op == "SLT" ){

        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

       declaration::reg[rdNow] = outCome;

    }
    else if( op == "SLL" ){

        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

      declaration::reg[rdNow] = outCome;

    }
    else if( op == "SRL" ){

        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rdNow] = outCome;

    }
    else if( op == "SRA" ){


        if( rdNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

       declaration::reg[rdNow] = outCome;

    }


    else if( op == "ADDI" ){

        if( rtNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

       declaration::reg[rtNow] = outCome;
        //test << "addi" << endl;
    }

    else if( op == "ADDIU" ){


        if( rtNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rtNow] = outCome;

    }

    else if ( op == "LW"  || op == "LH" || op == "LHU" || op == "LB" || op == "LBU" ){

        if( rtNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rtNow] = outCome;
    }


    else if( op == "LUI" ){


        if( rtNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }


        declaration::reg[rtNow] = outCome;

    }

    else if( op == "ANDI" ){

        if( rtNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

       declaration::reg[rtNow] = outCome;

    }

    else if( op == "ORI" ){

         if( rtNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rtNow] = outCome;

    }

    else if( op == "NORI" ){


        if( rtNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }

        declaration::reg[rtNow] = outCome;

    }

    else if( op == "SLTI" ){

         if( rtNow == 0 ){
            declaration::writeToZero = 1;
            return;
        }
        declaration::reg[rtNow] = outCome;

    }

    /*declaration::PC += 4;
    pipereg::IF = declaration::iMemory[ declaration::PC >> 2 ];*/

    return;


}
