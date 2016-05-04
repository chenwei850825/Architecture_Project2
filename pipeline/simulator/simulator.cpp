
#include"loading.h"
#include"IF.h"
#include"ID.h"
#include"EX.h"
#include"DM.h"
#include"WB.h"
#include"result.h"
#include"hazard.h"
#include"declaration.h"
#include"pipereg.h"
using namespace std;

int main(void)
{

    loading loads;
    loads.load();

    IF instructionFetch;
    ID instructionDecode;
    EX aluExecution;
    DM dataMemoryAccess;
    WB writeBack;
    result results;
    hazard hazardDetect;

    fstream outputs, errors;
    outputs.open("snapshot.rpt", ios::out | ios::binary );
    errors.open("error_dump.rpt", ios::out | ios::binary );



    while(1){

        results.output(outputs);



        writeBack.exe();
        results.errorDetect(errors);

        dataMemoryAccess.exe();
        results.errorDetect(errors);

        aluExecution.exe();
        results.errorDetect(errors);
        if( declaration::halt >= 5 )
            break;

        instructionDecode.exe();

        instructionFetch.exe();


        hazardDetect.exe();

        if( declaration::halt >= 5 )
            break;





    }


    outputs.close();
    return 0;


}
