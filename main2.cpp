#include <iostream>
#include <string>
#include <vector> 

#include "mitarbeiter.h"
//#include "firma.h"
#include "intervall.h"
#include "wartungsplan.h"
#include "maschfirma.h"

int main(){
    Intervall i = Intervall(10);
    std::cout<<i.getlaenge_Intervall()<<std::endl;
    return 0;
}