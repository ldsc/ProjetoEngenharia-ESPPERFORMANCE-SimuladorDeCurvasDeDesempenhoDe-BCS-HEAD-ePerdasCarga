#include <vector>
#include <iostream>
#include <cmath>

#include "CHeadTeorico.h"
#include "CBombaBCS.h"

using namespace std;

void CHeadTeorico::Informacoes(){
cout << "===================================================================================================================\n";
cout << "\n";
cout << "Para o calculo da altura de elevacao teorica foram considerados os seguintes parametros \n";
cout << "constantes inerentes ao modelo de BCS utilizado nas simulacoes (SLB-REDA GN7000):\n";
cout << "angulo entre velocidade relativa e direcao tangencial na entrada do rotor = 28 graus\n";
cout << "angulo entre velocidade relativa e direcao tangencial na saida do rotor = 36 graus\n";
cout << "altura do canal na entrada do rotor = 0,0173 m\n";
cout << "altura do canal na saida do rotor = 0,0157 m";
cout << "\nraio da entrada do rotor = 0,0445 m\n";
cout << "raio da saida do rotor = 0,0255 m\n";
cout << "numero de aletas = 7\n";
cout << "fator de correcao para numero finito de aletas = 0,71\n";
cout << "aceleracao da gravidade = 9,81 m\n";
cout << "\n";
cout <<"=================================================================================================================="<<endl;
}

double CHeadTeorico:: AlturaTeorica (CBombaBCS& bcs) {
    for (int i = 0; i< hteorico.size(); i++){
    hteorico [i] = 0.07238*((pow(0.0445*bcs.rotacao, 2)) - (pow(0.0255*bcs.rotacao, 2))) + 0.2424*bcs.rotacao*bcs.vazao[i];// formulação como função das variáveis
    }
}
