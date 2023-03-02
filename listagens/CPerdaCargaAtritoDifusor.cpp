#include <vector>
#include <iostream>
#include <cmath>

#include "CPerdaCargaAtritoDifusor.h"

using namespace std;

void CPerdaCargaAtritoDifusor::Informacoes(){
    cout <<"===================================================================================================================\n";
    cout << "                                                                                                                                             \n";
    cout<<"Para o calculo da perda de carga por atrito no rotor foram considerados os seguintes parametros \n";
    cout<<"constantes inerentes ao modelo de BCS utilizado nas simulacoes (SLB-REDA GN7000):\n";
    cout<<"raio medio da entrada do difusor = 0,04775 m\n";
    cout<<"raio medio da saida do difusor = 0,0290 m\n";
    cout<<"diametro hidraulico da secao do difusor = 0,02843 m\n";
    cout<<"altura media do canal do difusor = 0,01425 m\n";
    cout<<"angulo relativo medio do escoamento entre entrada e saida do difusor = 32 graus\n";
    cout << "                                                                                                                  \n";
    cout <<"=================================================================================================================="<<endl;
}

double CPerdaCargaAtritoDifusor::PerdaCarga(CFluido& fluido, CBombaBCS& bcs){
    for (int i = 0; i<pc.size(); i++){
            pc[i] = 2752 * (pow (bcs.vazao[i], 2))*(pow((8.58 *fluido.massaEspecifica *bcs.vazao[i])/ (fluido.viscosidade * pow(10,-3)), -0.611));
    }
}
