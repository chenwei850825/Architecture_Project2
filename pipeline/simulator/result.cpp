#include"result.h"


result::result()
{
    ;
}

void result::output( fstream &ostream)
{


    ostream << "cycle " << dec << declaration::cycle << endl;
    for( int i = 0; i < 32; i++ ){
        ostream << "$" << setw(2) << setfill('0') << dec <<   i;
        ostream << ": 0x" << setw(8) << setfill('0') << uppercase << hex << declaration::reg[i] << endl;
    }
    ostream << "PC: " << "0x" << setw(8) << setfill('0') << uppercase << hex << declaration::PC << endl;


    if( pipereg::IF_Hazard == "STALLED" ){
        ostream  << "IF: " << "0x" << setw(8) << setfill('0') << uppercase << hex << pipereg::IF.to_ulong();
        ostream << " to_be_stalled" << endl;
    }

    else if ( pipereg::IF_Hazard == "FLUSHED" ){
        ostream  << "IF: " << "0x" << setw(8) << setfill('0') << uppercase << hex << pipereg::IF.to_ulong();
        ostream << " to_be_flushed" << endl;
    }
    else
        ostream << "IF: " << "0x" << setw(8) << setfill('0') << uppercase << hex << pipereg::IF.to_ulong() << endl;



    if( pipereg::ID_Hazard == "STALLED"  ){
        ostream << "ID: " <<  pipereg::ID;
        ostream << " to_be_stalled" << endl;
    }
    else if ( pipereg::ID_Hazard != "NO_HAZARD" )
        ostream << "ID: " <<  pipereg::ID_HazardHandel << endl;
    else
        ostream << "ID: " <<  pipereg::ID<< endl;


    if( pipereg::EX_Hazard != "NO_HAZARD"  )
        ostream << "EX: " <<  pipereg::EX_HazardHandel << endl;
    else
        ostream << "EX: " <<  pipereg::EX << endl;


    ostream << "DM: " <<  pipereg::MEM << endl;
    ostream << "WB: " <<  pipereg::WB << endl;

    ostream << endl << endl;

}

void result::errorDetect( fstream &ostream )
{

    if( declaration::writeToZero == 1 ){
        ostream << "In cycle " << declaration::cycle << ": Write $0 Error\n";
        declaration::writeToZero = 0;
    }

    if( declaration::numberOverflow == 1 ){
        ostream << "In cycle " << declaration::cycle << ": Number Overflow\n";
        declaration::numberOverflow = 0;
    }

    if( declaration::memoryOverflow == 1 ){
        ostream << "In cycle " << declaration::cycle << ": Address Overflow\n";
        declaration::memoryOverflow  = 0;
    }

    if( declaration::dataMisalign == 1 ){
        ostream << "In cycle " << declaration::cycle << ": Misalignment Error\n";
        declaration::dataMisalign = 0;
    }


}
