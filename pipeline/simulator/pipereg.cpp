
#include"pipereg.h"

    bitset<32> pipereg::IF = 0;
    string pipereg::IF_Hazard = "NO_HAZARD";
    string pipereg::IF_HazardHandel = "";

    bitset<5>pipereg::IF_ID_rs = 0;;
    bitset<5>pipereg::IF_ID_rt = 0;
    bitset<5>pipereg::IF_ID_rd = 0;
    int pipereg::IF_ID_rsValue = 0;
    int pipereg::IF_ID_rtValue = 0;
    int pipereg::IF_ID_rdValue = 0;
    bitset<5>pipereg::IF_ID_shamt = 0;
    bitset<16>pipereg::IF_ID_immediate = 0;
    bitset<26>pipereg::IF_ID_address = 0;
    int pipereg::IF_ID_RegWrite = 0;

    bitset<32> pipereg::ID_Instruction = 0;
    string pipereg::ID = "NOP";
    string pipereg::ID_Type = "NOP";
    string pipereg::ID_Hazard = "NO_HAZARD";
    string pipereg::ID_HazardHandel = "";


    bitset<5> pipereg::ID_EX_rs = 0;
    bitset<5> pipereg::ID_EX_rt = 0;
    bitset<5> pipereg::ID_EX_rd = 0;
    int pipereg::ID_EX_rsValue = 0;
    int pipereg::ID_EX_rtValue = 0;
    int pipereg::ID_EX_rdValue = 0;
    bitset<5> pipereg::ID_EX_shamt = 0;
    bitset<16> pipereg::ID_EX_immediate = 0;
    bitset<26> pipereg::ID_EX_address = 0;
    int pipereg::ID_EX_RegWrite = 0;

    string pipereg::EX = "NOP";
    string pipereg::EX_Type = "NOP";
    string pipereg::EX_Hazard = "NO_HAZARD";
    string pipereg::EX_HazardHandel = "";

    bitset<5> pipereg::EX_MEM_rs = 0;
    bitset<5> pipereg::EX_MEM_rt = 0;
    bitset<5> pipereg::EX_MEM_rd = 0;
    int pipereg::EX_MEM_rsValue = 0;
    int pipereg::EX_MEM_rtValue = 0;
    int pipereg::EX_MEM_rdValue = 0;
    bitset<5> pipereg::EX_MEM_shamt = 0;
    bitset<16> pipereg::EX_MEM_immediate = 0;
    bitset<26> pipereg::EX_MEM_address = 0;
    int pipereg::EX_MEM_outCome = 0;
    int pipereg::EX_MEM_RegWrite = 0;


    string pipereg::MEM = "NOP";
    string pipereg::MEM_Type = "NOP";

    bitset<5> pipereg::MEM_WB_rs = 0;
    bitset<5> pipereg::MEM_WB_rt = 0;
    bitset<5> pipereg::MEM_WB_rd = 0;
    int pipereg::MEM_WB_rsValue = 0;
    int pipereg::MEM_WB_rtValue = 0;
    int pipereg::MEM_WB_rdValue = 0;
    bitset<5> pipereg::MEM_WB_shamt = 0;
    bitset<16> pipereg::MEM_WB_immediate = 0;
    bitset<26> pipereg::MEM_WB_address = 0;
    int pipereg::MEM_WB_outCome = 0;
    int pipereg::MEM_WB_RegWrite = 0;

    string pipereg::WB = "NOP";
    string pipereg::WB_Type = "NOP";



