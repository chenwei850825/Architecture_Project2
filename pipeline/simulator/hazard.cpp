#include"hazard.h"
#include <sstream>
#include<iostream>

using namespace std;

string int2str(unsigned long &);
string int2str(unsigned long &i)
{
    string s;
    stringstream ss(s);
    ss << i;
    return ss.str();
}

hazard::hazard()
{

}

void hazard::exe()
{




    if( pipereg::ID == "BEQ" || pipereg::ID == "BNE" || pipereg::ID == "BGTZ" || pipereg::ID == "JR" )
    {
        branchForwarding();
        branchStall();
    }

    nonBranchForwarding();
    nonBranchStall();


    flush();

}
void hazard::nonBranchForwarding()
{

    if( pipereg::EX == "BEQ" || pipereg::EX == "BNE" || pipereg::EX == "BGTZ" || pipereg::EX == "JR" )
        return;


    /******  forward  from EX/DM to ID/EX    ************/


    if( pipereg::ID_EX_RegWrite == 1 )
    {
        if ( pipereg::EX_Type == "I")
        {

            if ( pipereg::ID_Type == "R" )
            {

                if( pipereg::ID_EX_rt != 0 && ( pipereg::ID_EX_rt == pipereg::IF_ID_rs ) && pipereg::ID != "SLL" && pipereg::ID != "SRL" && pipereg::ID != "SRA")
                {
                    if( pipereg::EX == "LW" || pipereg::EX == "LH" || pipereg::EX == "LHU" || pipereg::EX == "LB" || pipereg::EX == "LBU" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                        return;
                    }


                }

                else if( pipereg::ID_EX_rt != 0 && ( pipereg::ID_EX_rt == pipereg::IF_ID_rt ) )
                {
                    if( pipereg::EX == "LW" || pipereg::EX == "LH" || pipereg::EX == "LHU" || pipereg::EX == "LB" || pipereg::EX == "LBU" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                        return;
                    }



                }

            }

            else if ( pipereg::ID_Type == "I" )
            {

                if( pipereg::ID_EX_rt != 0 && ( pipereg::ID_EX_rt == pipereg::IF_ID_rs ) && pipereg::ID != "LUI" )
                {

                    if( pipereg::EX == "LW" || pipereg::EX == "LH" || pipereg::EX == "LHU" || pipereg::EX == "LB" || pipereg::EX == "LBU" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                        return;
                    }


                }
            }
        }


    }



    if( pipereg::EX_MEM_RegWrite == 1 )
    {

        if( pipereg::MEM_Type == "R" )
        {

            if( pipereg::EX_Type == "R")
            {

                if( pipereg::EX_MEM_rd != 0 && ( pipereg::EX_MEM_rd == pipereg::ID_EX_rs ) && pipereg::EX != "SLL" && pipereg::EX != "SRL" && pipereg::EX != "SRA" )
                {
                    pipereg::EX_Hazard = "sFORWARDING";
                    unsigned long tmp = pipereg::ID_EX_rs.to_ulong();
                    string tmp1 = pipereg::EX;
                    string tmp2 = int2str( tmp );
                    pipereg::EX_HazardHandel = tmp1 + " fwd_EX-DM_rs_$" + tmp2;

                }

                else if( pipereg::EX_MEM_rd != 0 && ( pipereg::EX_MEM_rd == pipereg::ID_EX_rt )  )
                {

                    pipereg::EX_Hazard = "tFORWARDING";
                    unsigned long tmp = pipereg::ID_EX_rt.to_ulong();
                    string tmp1 = pipereg::EX;
                    string tmp2 = int2str( tmp );
                    pipereg::EX_HazardHandel = tmp1 + " fwd_EX-DM_rt_$" + tmp2;


                }

            }

            else if ( pipereg::EX_Type == "I" )
            {

                if( pipereg::EX_MEM_rd != 0 && ( pipereg::EX_MEM_rd == pipereg::ID_EX_rs ) && pipereg::EX != "LUI" )
                {
                    pipereg::EX_Hazard = "sFORWARDING";
                    unsigned long tmp = pipereg::ID_EX_rs.to_ulong();
                    string tmp1 = pipereg::EX;
                    string tmp2 = int2str( tmp );
                    pipereg::EX_HazardHandel = tmp1 + " fwd_EX-DM_rs_$" + tmp2;

                }
            }

        }

        else if ( pipereg::MEM_Type == "I")
        {

            if ( pipereg::EX_Type == "R" )
            {

                if( pipereg::EX_MEM_rt != 0 && ( pipereg::EX_MEM_rt == pipereg::ID_EX_rs ) && pipereg::EX != "SLL" && pipereg::EX != "SRL" && pipereg::EX != "SRA")
                {


                    pipereg::EX_Hazard = "sFORWARDING";
                    unsigned long tmp = pipereg::ID_EX_rs.to_ulong();
                    string tmp1 = pipereg::EX;
                    string tmp2 = int2str( tmp );
                    pipereg::EX_HazardHandel = tmp1 + " fwd_EX-DM_rs_$" + tmp2;

                }

                else if( pipereg::EX_MEM_rt != 0 && ( pipereg::EX_MEM_rt == pipereg::ID_EX_rt ) )
                {



                    pipereg::EX_Hazard = "tFORWARDING";
                    unsigned long tmp = pipereg::ID_EX_rt.to_ulong();
                    string tmp1 = pipereg::EX;
                    string tmp2 = int2str( tmp );
                    pipereg::EX_HazardHandel = tmp1 + " fwd_EX-DM_rt_$" + tmp2;

                }

            }

            else if ( pipereg::EX_Type == "I" )
            {

                if( pipereg::EX_MEM_rt != 0 && ( pipereg::EX_MEM_rt == pipereg::ID_EX_rs ) && pipereg::EX != "LUI" )
                {


                    pipereg::EX_Hazard = "sFORWARDING";
                    unsigned long tmp = pipereg::ID_EX_rs.to_ulong();
                    string tmp1 = pipereg::EX;
                    string tmp2 = int2str( tmp );
                    pipereg::EX_HazardHandel = tmp1 + " fwd_EX-DM_rs_$" + tmp2;


                }
            }
        }


    }


}

void hazard::branchForwarding()
{
    /******  forward  from EX/DM to IF/ID    ************/



    if( pipereg::EX_MEM_RegWrite == 1 )
    {

        if( pipereg::MEM_Type == "R" )
        {
            if( pipereg::ID != "BGTZ" && pipereg::ID != "JR" )
            {
                if( pipereg::EX_MEM_rd != 0 && ( pipereg::EX_MEM_rd == pipereg::IF_ID_rs ) )
                {
                    pipereg::ID_Hazard = "sFORWARDING";
                    unsigned long tmp = pipereg::IF_ID_rs.to_ulong();
                    string tmp1 = pipereg::ID;
                    string tmp2 = int2str( tmp );
                    pipereg::ID_HazardHandel = tmp1 + " fwd_EX-DM_rs_$" + tmp2;

                }

                else if ( pipereg::EX_MEM_rd != 0 && ( pipereg::EX_MEM_rd == pipereg::IF_ID_rt ) )
                {
                    pipereg::ID_Hazard = "tFORWARDING";
                    unsigned long tmp = pipereg::IF_ID_rt.to_ulong();
                    string tmp1 = pipereg::ID;
                    string tmp2 = int2str( tmp );
                    pipereg::ID_HazardHandel = tmp1 + " fwd_EX-DM_rt_$" + tmp2;

                }
            }

            else
            {

                if( pipereg::EX_MEM_rd != 0 && ( pipereg::EX_MEM_rd == pipereg::IF_ID_rs ) )
                {
                    pipereg::ID_Hazard = "sFORWARDING";
                    unsigned long tmp = pipereg::IF_ID_rs.to_ulong();
                    string tmp1 = pipereg::ID;
                    string tmp2 = int2str( tmp );
                    pipereg::ID_HazardHandel = tmp1 + " fwd_EX-DM_rs_$" + tmp2;

                }

            }

        }

        else if ( pipereg::MEM_Type == "I")
        {

            if( pipereg::ID != "BGTZ"  && pipereg::ID != "JR"  )
            {

                if( pipereg::EX_MEM_rt != 0 && ( pipereg::EX_MEM_rt == pipereg::IF_ID_rs ) )
                {
                    if( pipereg::MEM == "LW" || pipereg::MEM == "LH" || pipereg::MEM == "LHU" || pipereg::MEM == "LB" || pipereg::MEM == "LBU" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                        return;
                    }

                    pipereg::ID_Hazard = "sFORWARDING";
                    unsigned long tmp = pipereg::IF_ID_rs.to_ulong();
                    string tmp1 = pipereg::ID;
                    string tmp2 = int2str( tmp );
                    pipereg::ID_HazardHandel = tmp1 + " fwd_EX-DM_rs_$" + tmp2;

                }

                else if ( pipereg::EX_MEM_rt != 0 && ( pipereg::EX_MEM_rt == pipereg::IF_ID_rt ) )
                {
                    if( pipereg::MEM == "LW" || pipereg::MEM == "LH" || pipereg::MEM == "LHU" || pipereg::MEM == "LB" || pipereg::MEM == "LBU" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                        return;
                    }

                    pipereg::ID_Hazard = "tFORWARDING";
                    unsigned long tmp = pipereg::IF_ID_rt.to_ulong();
                    string tmp1 = pipereg::ID;
                    string tmp2 = int2str( tmp );
                    pipereg::ID_HazardHandel = tmp1 + " fwd_EX-DM_rt_$" + tmp2;

                }
            }

            else
            {
                if( pipereg::EX_MEM_rt != 0 && ( pipereg::EX_MEM_rt == pipereg::IF_ID_rs ) )
                {
                    if( pipereg::MEM == "LW" || pipereg::MEM == "LH" || pipereg::MEM == "LHU" || pipereg::MEM == "LB" || pipereg::MEM == "LBU" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                        return;
                    }

                    pipereg::ID_Hazard = "sFORWARDING";
                    unsigned long tmp = pipereg::IF_ID_rs.to_ulong();
                    string tmp1 = pipereg::ID;
                    string tmp2 = int2str( tmp );
                    pipereg::ID_HazardHandel = tmp1 + " fwd_EX-DM_rs_$" + tmp2;

                }

            }

        }


    }


}

void hazard::nonBranchStall()
{
    if( pipereg::ID == "BEQ" || pipereg::ID == "BNE" || pipereg::ID == "BGTZ" || pipereg::ID == "JR" )
        return;

    if( pipereg::EX_MEM_RegWrite == 1 )
    {


        if( pipereg::MEM_Type == "R" )
        {
            if( pipereg::ID_Type == "R")
            {

                if( pipereg::EX_MEM_rd != 0 && ( pipereg::EX_MEM_rd == pipereg::IF_ID_rs ) && pipereg::ID != "SLL" && pipereg::ID != "SRL" && pipereg::ID != "SRA" )
                {
                    if(  ( pipereg::EX_Type == "R" && pipereg::EX_MEM_rd != pipereg::ID_EX_rd ) || ( pipereg::EX_Type == "I" && pipereg::EX_MEM_rd != pipereg::ID_EX_rt ) || pipereg::EX_Type == "NOP" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                    }

                }

                else if( pipereg::EX_MEM_rd != 0 && ( pipereg::EX_MEM_rd == pipereg::IF_ID_rt ) )
                {

                    if(  ( pipereg::EX_Type == "R" && pipereg::EX_MEM_rd != pipereg::ID_EX_rd ) || ( pipereg::EX_Type == "I" && pipereg::EX_MEM_rd != pipereg::ID_EX_rt ) || pipereg::EX_Type == "NOP" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                    }

                }

            }

            else if ( pipereg::ID_Type == "I" )
            {

                if( pipereg::EX_MEM_rd != 0 && ( pipereg::EX_MEM_rd == pipereg::IF_ID_rs ) && pipereg::ID != "LUI" )
                {

                    if(  ( pipereg::EX_Type == "R" && pipereg::EX_MEM_rd != pipereg::ID_EX_rd ) || ( pipereg::EX_Type == "I" && pipereg::EX_MEM_rd != pipereg::ID_EX_rt ) || pipereg::EX_Type == "NOP" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                    }

                }
            }

        }


        else if( pipereg::MEM_Type == "I" )
        {

            if ( pipereg::ID_Type == "R" )
            {

                if( pipereg::EX_MEM_rt != 0 && ( pipereg::EX_MEM_rt == pipereg::IF_ID_rs ) && pipereg::ID != "SLL" && pipereg::ID != "SRL" && pipereg::ID != "SRA" )
                {

                    if(  ( pipereg::EX_Type == "R" && pipereg::EX_MEM_rt != pipereg::ID_EX_rd ) || ( pipereg::EX_Type == "I" && pipereg::EX_MEM_rt != pipereg::ID_EX_rt ) || pipereg::EX_Type == "NOP" )
                    {

                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                    }

                }

                else if( pipereg::EX_MEM_rt != 0 && ( pipereg::EX_MEM_rt == pipereg::IF_ID_rt )  )
                {

                    if(  ( pipereg::EX_Type == "R" && pipereg::EX_MEM_rt != pipereg::ID_EX_rd ) || ( pipereg::EX_Type == "I" && pipereg::EX_MEM_rt != pipereg::ID_EX_rt ) || pipereg::EX_Type == "NOP" )
                    {

                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";

                    }

                }

            }

            else if ( pipereg::ID_Type == "I" )
            {

                if( pipereg::EX_MEM_rt != 0 && ( pipereg::EX_MEM_rt == pipereg::IF_ID_rs ) && pipereg::ID != "LUI" )
                {

                    if(  ( pipereg::EX_Type == "R" && pipereg::EX_MEM_rt != pipereg::ID_EX_rd ) || ( pipereg::EX_Type == "I" && pipereg::EX_MEM_rt != pipereg::ID_EX_rt ) || pipereg::EX_Type == "NOP" )
                    {
                        pipereg::IF_Hazard = "STALLED";
                        pipereg::ID_Hazard = "STALLED";
                    }

                }
            }


        }


    }



}


void hazard::branchStall()
{
    if( pipereg::ID_EX_RegWrite == 1 )
    {
        if( pipereg::EX_Type == "R")
        {
            if( pipereg::ID != "BGTZ"  && pipereg::ID != "JR" )
            {

                if( pipereg::ID_EX_rd != 0 && ( pipereg::ID_EX_rd == pipereg::IF_ID_rs ) )
                {
                    pipereg::IF_Hazard = "STALLED";
                    pipereg::ID_Hazard = "STALLED";

                }

                else if( pipereg::ID_EX_rd != 0 && ( pipereg::ID_EX_rd == pipereg::IF_ID_rt ) )
                {

                    pipereg::IF_Hazard = "STALLED";
                    pipereg::ID_Hazard = "STALLED";

                }

            }

            else
            {

                if( pipereg::ID_EX_rd != 0 && ( pipereg::ID_EX_rd == pipereg::IF_ID_rs )  )
                {

                    pipereg::IF_Hazard = "STALLED";
                    pipereg::ID_Hazard = "STALLED";


                }
            }


        }



        else if ( pipereg::EX_Type == "I")
        {

            if( pipereg::ID != "BGTZ"  && pipereg::ID != "JR" )
            {

                if( pipereg::ID_EX_rt != 0 && ( pipereg::ID_EX_rt == pipereg::IF_ID_rs ) )
                {
                    pipereg::IF_Hazard = "STALLED";
                    pipereg::ID_Hazard = "STALLED";

                }

                else if( pipereg::ID_EX_rt != 0 && ( pipereg::ID_EX_rt == pipereg::IF_ID_rt ) )
                {

                    pipereg::IF_Hazard = "STALLED";
                    pipereg::ID_Hazard = "STALLED";

                }

            }

            else
            {

                if( pipereg::ID_EX_rt != 0 && ( pipereg::ID_EX_rt == pipereg::IF_ID_rs )  )
                {

                    pipereg::IF_Hazard = "STALLED";
                    pipereg::ID_Hazard = "STALLED";


                }
            }
        }
    }

}




void hazard::flush()
{

    if ( pipereg::ID_Hazard == "STALLED" )
        return;



    rs = pipereg::IF_ID_rs;
    rt = pipereg::IF_ID_rt;
    rd = pipereg::IF_ID_rd;
    rsValue = declaration::reg[ ( unsigned )( rs.to_ulong() ) ];
    rtValue = declaration::reg[ ( unsigned )( rt.to_ulong() ) ];
    rdValue = declaration::reg[ ( unsigned )( rd.to_ulong() ) ];


    if( pipereg::MEM_WB_RegWrite == 1 )
    {

        if( pipereg::WB_Type == "R" )
        {
            if( rs == pipereg::MEM_WB_rd )
                rsValue = pipereg::MEM_WB_outCome;
            else if ( rt == pipereg::MEM_WB_rd )
                rtValue = pipereg::MEM_WB_outCome;
        }

        else if (pipereg::WB_Type == "I" )
        {
            if( rs == pipereg::MEM_WB_rt )
                rsValue = pipereg::MEM_WB_outCome;
            else if ( rt == pipereg::MEM_WB_rt )
                rtValue = pipereg::MEM_WB_outCome;
        }

    }

    if( pipereg::ID_Hazard[1] == 'F' )
    {

        if( pipereg::ID_Hazard[0] == 's' )
            rsValue = pipereg::EX_MEM_outCome;
        else
            rtValue = pipereg::EX_MEM_outCome;

    }




    if( pipereg::ID == "JR" || pipereg::ID == "J" || pipereg::ID == "JAL" )
        pipereg::IF_Hazard = "FLUSHED";

    else if( pipereg::ID == "BEQ" )
    {
        if( rsValue == rtValue  )
            pipereg::IF_Hazard = "FLUSHED";
    }

    else if ( pipereg::ID == "BNE" )
    {
        if( rsValue  != rtValue  )
            pipereg::IF_Hazard = "FLUSHED";
    }

    else if ( pipereg::ID == "BGTZ" )
    {
        if( rsValue  > 0 )
            pipereg::IF_Hazard = "FLUSHED";

    }


}


