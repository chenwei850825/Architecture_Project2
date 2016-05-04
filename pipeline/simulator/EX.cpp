#include "EX.h"
#include<iostream>

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


EX::EX()
{
    ;
}

void EX::exe()
{



    op = pipereg::EX;
    op_type = pipereg::EX_Type;
    rs = pipereg::ID_EX_rs;
    rt = pipereg::ID_EX_rt;
    rd = pipereg::ID_EX_rd;
    if( pipereg::EX_Hazard != "NO_HAZARD" ){

        if( pipereg::EX_Hazard[0] == 's' ){
            rsValue = pipereg::EX_MEM_outCome;
            rtValue = declaration::reg[ ( unsigned )( rt.to_ulong() ) ];
        }
        else{
            rsValue = declaration::reg[ ( unsigned )( rs.to_ulong() ) ];
            rtValue = pipereg::EX_MEM_outCome;
        }
        pipereg::EX_Hazard = "NO_HAZARD";

    }
    else{
        rsValue = declaration::reg[ ( unsigned )( rs.to_ulong() ) ];
        rtValue = declaration::reg[ ( unsigned )( rt.to_ulong() ) ];
    }
    rdValue = declaration::reg[ ( unsigned )( rd.to_ulong() ) ];
    pipereg::EX_MEM_rsValue = rsValue;
    pipereg::EX_MEM_rtValue = rtValue;
    pipereg::EX_MEM_rdValue = rdValue;
    shamt = pipereg::ID_EX_shamt;
    immediate = pipereg::ID_EX_immediate;
    address = pipereg::ID_EX_address;
    pipereg::EX_MEM_RegWrite = 0;






    unsigned shamtNow = ( unsigned )( shamt.to_ulong() );
    unsigned immediateNow = ( unsigned )( immediate.to_ulong() );
    int immediateSigned = bitset_to_long(immediate);
   

    if( op == "ADD" ) {

        overflow = rsValue + rtValue;
        if( rsValue > 0 && rtValue > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && rtValue < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;


        outCome = rsValue + rtValue;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "add" << endl;
    }
    else if( op == "ADDU" ){


        outCome = rsValue + rtValue;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "addu" << endl;
    }
    else if( op == "SUB" ){

        int complement = - ( rtValue );
        overflow = rsValue + complement;
        if( rsValue > 0 && complement > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && complement < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;


        outCome = rsValue + complement;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "sub" << endl;
    }


    else if( op == "AND" ){


        outCome = rsValue & rtValue;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "and" << endl;
    }
    else if( op == "OR" ){



        outCome = rsValue | rtValue;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "or" << endl;
    }
    else if( op == "XOR" ){


        outCome = rsValue ^ rtValue;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "xor" << endl;
    }
    else if( op == "NOR" ){

        outCome = ~( rsValue | rtValue ) ;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "nor" << endl;
    }
    else if( op == "NAND" ){


        outCome = ~( rsValue & rtValue );
        pipereg::EX_MEM_RegWrite = 1;
        //test << "nand" << endl;
    }
    else if( op == "SLT" ){


        outCome = ( rsValue < rtValue );
        pipereg::EX_MEM_RegWrite = 1;
        //test << "slt" << endl;
    }
    else if( op == "SLL" ){

        outCome = (unsigned)rtValue << shamtNow;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "sll" << endl;
    }
    else if( op == "SRL" ){


        outCome = (unsigned)rtValue >> shamtNow;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "srl" << endl;
    }
    else if( op == "SRA" ){


        outCome = rtValue >> shamtNow;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "sra" << endl;
    }


    else if( op == "ADDI" ){

        overflow = rsValue + immediateSigned;
        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;



        outCome = rsValue + immediateSigned;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "addi" << endl;
    }

    else if( op == "ADDIU" ){


        outCome = rsValue + immediateSigned;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "addiu" << endl;
    }

    else if( op == "LW" ){



        overflow = rsValue + immediateSigned;
        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if ( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;





        outCome = rsValue + immediateSigned + 3;
        pipereg::EX_MEM_RegWrite = 1;

        //test << "lw" << endl;
    }

    else if( op == "LH" ){




        overflow = rsValue + immediateSigned;
        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;



        outCome = rsValue + immediateSigned + 1;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "lh" << endl;
    }

    else if( op == "LHU" ){


        overflow = rsValue + immediateSigned;
        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;




        outCome = rsValue + immediateSigned + 1;
        pipereg::EX_MEM_RegWrite = 1;

        //test << "lhu" << endl;
    }

    else if( op == "LB" ){




        overflow = rsValue + immediateSigned;
        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;



        outCome = rsValue + immediateSigned;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "lb" << endl;
    }

    else if( op == "LBU" ){



        overflow = rsValue + immediateSigned;
        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;


        outCome = rsValue + immediateSigned;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "lbu" << endl;
    }

    else if( op == "SW" ){


        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;





        outCome = rsValue + immediateSigned + 3;

        //test << "sw" << endl;
    }

    else if( op == "SH" ){


        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;






        outCome = rsValue + immediateSigned + 1;

        //test << "sh" << endl;
    }

    else if( op == "SB" ){



        if( rsValue > 0 && immediateSigned > 0 && overflow <= 0 )
            declaration::numberOverflow = 1;
        else if( rsValue < 0 && immediateSigned < 0 && overflow >= 0 )
            declaration::numberOverflow = 1;






        outCome = rsValue + immediateSigned;
        //test << "sb" << endl;
    }

    else if( op == "LUI" ){

        outCome = immediateNow << 16;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "lui" << endl;
    }

    else if( op == "ANDI" ){



        outCome = rsValue  & immediateNow;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "andi" << endl;
    }

    else if( op == "ORI" ){



        outCome  =  rsValue  | immediateNow;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "ori" << endl;
    }

    else if( op == "NORI" ){



        outCome  = ~(  rsValue | immediateNow );
        pipereg::EX_MEM_RegWrite = 1;
        //test << "nori" << endl;
    }

    else if( op == "SLTI" ){


        outCome  = rsValue  < immediateSigned;
        pipereg::EX_MEM_RegWrite = 1;
        //test << "slti" << endl;
    }


    else if( op == "HALT" ){

    }



    pipereg::MEM = op;
    pipereg::MEM_Type = op_type;
    pipereg::EX_MEM_rs = rs;
    pipereg::EX_MEM_rt = rt;
    pipereg::EX_MEM_rd = rd;

    pipereg::EX_MEM_shamt = shamt;
    pipereg::EX_MEM_immediate = immediate;
    pipereg::EX_MEM_address = address;
    pipereg::EX_MEM_outCome = outCome;


    return;
}
