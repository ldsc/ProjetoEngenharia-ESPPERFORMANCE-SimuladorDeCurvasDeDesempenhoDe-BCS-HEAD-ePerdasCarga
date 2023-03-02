#include <iostream>
#include "CPerdaCargaRecirculacao.h"

using namespace std;

double CPerdaCargaRecirculacao::PerdaCarga(){
    for (int i = 0; i< pc.size(); i++){
            pc[i]=0.0;
    }
}

void CPerdaCargaRecirculacao::Informacoes(){
    cout 
    <<"===================================================================================================================\n"
    <<"Para a perda de carga por recirculacao e usada a definicao de Gullich (1999), que considera essa perda em\n" 
    <<"escoamentos em bomba centrifuga desprezivel.\n"
    <<"==============================================================================================================="<<endl;
}
