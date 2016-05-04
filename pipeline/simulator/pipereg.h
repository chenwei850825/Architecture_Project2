
#ifndef PIPEREG_H
#define PIPEREG_H

#include<bitset>
#include"declaration.h"
using  namespace std;

class pipereg
{
public:



    static bitset<32> IF;
    static string IF_Hazard;
    static string IF_HazardHandel;

    static bitset<5>IF_ID_rs;
    static bitset<5>IF_ID_rt;
    static bitset<5>IF_ID_rd;
    static int IF_ID_rsValue;
    static int IF_ID_rtValue;
    static int IF_ID_rdValue;
    static bitset<5>IF_ID_shamt;
    static bitset<16>IF_ID_immediate;
    static bitset<26>IF_ID_address;
    static int IF_ID_RegWrite;


    static string ID;
    static string ID_Type;
    static string ID_Hazard;
    static string ID_HazardHandel;
    static bitset<32> ID_Instruction;

    static bitset<5>ID_EX_rs;
    static bitset<5>ID_EX_rt;
    static bitset<5>ID_EX_rd;
    static int ID_EX_rsValue;
    static int ID_EX_rtValue;
    static int ID_EX_rdValue;
    static bitset<5>ID_EX_shamt;
    static bitset<16>ID_EX_immediate;
    static bitset<26>ID_EX_address;
    static int ID_EX_RegWrite;

    static string EX;
    static string EX_Type;
    static string EX_Hazard;
    static string EX_HazardHandel;

    static bitset<5>EX_MEM_rs;
    static bitset<5>EX_MEM_rt;
    static bitset<5>EX_MEM_rd;
    static int EX_MEM_rsValue;
    static int EX_MEM_rtValue;
    static int EX_MEM_rdValue;
    static bitset<5>EX_MEM_shamt;
    static bitset<16>EX_MEM_immediate;
    static bitset<26>EX_MEM_address;
    static int EX_MEM_outCome;
    static int EX_MEM_RegWrite;

    static string MEM;
    static string MEM_Type;

    static bitset<5>MEM_WB_rs;
    static bitset<5>MEM_WB_rt;
    static bitset<5>MEM_WB_rd;
    static int MEM_WB_rsValue;
    static int MEM_WB_rtValue;
    static int MEM_WB_rdValue;
    static bitset<5>MEM_WB_shamt;
    static bitset<16>MEM_WB_immediate;
    static bitset<26>MEM_WB_address;
    static int MEM_WB_outCome;
    static int MEM_WB_RegWrite;



    static string WB;
    static string WB_Type;


};


#endif // PIPEREG_H
