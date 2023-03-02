#include <vector>
#include <iostream>
#include <cmath>

#include "CPerdaCargaAtritoRotor.h"

using namespace std;

void CPerdaCargaAtritoRotor::Informacoes(){
cout <<"===================================================================================================================\n";
cout << "                                                                                                        \n";
cout<<"Para o calculo da perda de carga por atrito no rotor foram considerados os seguintes parametros constantes:\n";
cout<<"raio da entrada do rotor = 0,0445 m\n";
cout<<"raio da saida do rotor = 0,0255 m\n";
cout<<"diametro hidraulico da secao dpo rotor = 0,01655 m\n";
cout<<"altura media do canal = 0,0165 m\n";
cout<<"projecao do angulo da aleta no plano horizontal com relacao a vista lateral do rotor = 0,3810 rad\n";
cout<<"angulo entre aleta e plano horizontal com relacao a vista lateral do rotor em bomba de fluxo misto = 0,4189 rad\n";
cout<<"fator de atrito para correcao de canal retangular = 0,8889\n";
cout<<"fator de atrito para correcao de canal rotativo = 1\n";
cout << "                                                                                                                  \n";
cout <<"==================================================================================================================="<<endl;
}

double CPerdaCargaAtritoRotor::PerdaCarga(CFluido& fluido, CBombaBCS& bcs){

    for (int i = 0; i<10; i++){
            pc[i] = 50141* (pow (bcs.vazao[i],2))* (pow(((8580*fluido.massaEspecifica*bcs.vazao[i])/(fluido.viscosidade)), -0.611));
    }
}
