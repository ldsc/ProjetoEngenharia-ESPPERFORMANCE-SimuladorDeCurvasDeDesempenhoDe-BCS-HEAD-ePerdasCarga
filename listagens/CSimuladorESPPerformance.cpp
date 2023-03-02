#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>

#include "CSimuladorESPPerformance.h"
// #include "CGnuplot.h"
// #include "CFluido.h"
// #include "CBombaBCS.h"
// #include "CHeadTeorico.h"
// #include "CPerdaCargaAtritoDifusor.h"
// #include "CPerdaCargaAtritoDisco.h"
// #include "CPerdaCargaAtritoRotor.h"
// #include "CPerdaCargaChoque.h"
// #include "CPerdaCargaRecirculacao.h"

using namespace std;


void CSimuladorESPPerformance::Menu(){
cout << "\n==================================================================================================================";
cout << "\n==================                                ESP PERFORMANCE                              ===================";
cout << "\n================== SIMULADOR SIMPLIFICADO DE DESEMPENHO DE BCS BASEADO NAS ALTURAS DE ELEVACAO ===================";
cout << "\n==================================================================================================================\n";
cout << "\nDeseja simular com fluido de viscosidade igual a: 1 cP (Digite 1) ou 270 cP (Digite 2)?\n";
int opcaoMenuViscosidade;
cin >> opcaoMenuViscosidade;    cin.get();
cout <<"\nDeseja simular com bomba operando com rotacao de: 3500 rpm (Digite 1)  ou 1800 rpm (Digite 2)?\n";
int opcaoMenuRotacao;
cin >> opcaoMenuRotacao;
cin.get();
cout <<"\n==================================================================================================================="<<endl;

numeroIntervalos = 10;
alturaElevacao.resize(numeroIntervalos);
perdaCargaSegmento.resize(numeroIntervalos);

    if (opcaoMenuViscosidade == 1 and opcaoMenuRotacao == 1){
        fluido.viscosidade = 1;    ///< Viscosidade em centiPoise (cP)
        fluido.massaEspecifica = 997; ///< massa especifica em Kg/m3
        bcs.rotacao = (3500*2*M_PI)/60;    ///< Em rotacao por minuto (rpm), e necessario converter para radiano por segundo (rad/s)
        bcs.vazaoBEP = 0.01394 ;  ///< vazao em m3/s
        cout << "A simulacao ocorrera com fluido de massa especifica igual a 997 Kg/m3"<<endl;
    }

    else if (opcaoMenuViscosidade == 2 and opcaoMenuRotacao == 1){
        fluido.viscosidade = 270;   ///< Viscosidade em centiPoise (cP)
        fluido.massaEspecifica = 1260; ///< massa especifica em Kg/m3
        bcs.rotacao = (3500*2*M_PI)/60;    ///< Em rotacao por minuto (rpm), e necessario converter para radiano por segundo (rad/s)
        bcs.vazaoBEP = 0.0107 ;  ///< vazao em m3/s
        cout << "A simulacao ocorrera com fluido de massa especifica igual a 1260 Kg/m3"<<endl;
    }

    else if (opcaoMenuViscosidade == 1 and opcaoMenuRotacao == 2){
        fluido.viscosidade = 1;    ///< Viscosidade em centiPoise (cP)
        fluido.massaEspecifica = 997; ///< massa especifica em Kg/m3
        bcs.rotacao = (1800*2*M_PI)/60;    ///< Em rotacao por minuto (rpm), e necessario converter para radiano por segundo (rad/s)
        bcs.vazaoBEP = 0.0083 ; ///< vazao em m3/s
        cout << "A simulacao ocorrera com fluido de massa especifica igual a 997 Kg/m3"<<endl;;
    }

    else if (opcaoMenuViscosidade == 2 and opcaoMenuRotacao == 2){
        fluido.viscosidade = 270;    ///< Viscosidade em centiPoise (cP)
        fluido.massaEspecifica = 1260; ///< massa especifica em Kg/m3
        bcs.rotacao = (1800*2*M_PI)/60;    ///< Em rotacao por minuto (rpm), e necessario converter para radiano por segundo (rad/s)
        bcs.vazaoBEP = 0.00475 ;  ///< vazao em m3/s
        cout << "A simulacao ocorrera com fluido de massa especifica igual a 1260 Kg/m3"<<endl;
    }
}

void CSimuladorESPPerformance::PerdaCargaTotal() {
    for (int i = 0; i< perdaCargaSegmento.size(); i++){

        perdaCargaSegmento[i] = rotor[i] + choque[i] + recirculacao[i] + difusor[i] + disco[i];}
}

double CSimuladorESPPerformance :: AlturaElevacao(){

    /// Mostra menu que solicita dados fluido e bomba; seta numeroIntervalos
    Menu();

    /// Converte a vazão
    bcs.ConverteVazao();

    /// Calcula head teorico e informa constantes
    headTeorico.AlturaTeorica (bcs);
    headTeorico.Informacoes();

    /// Calcula perda de carga difusor e informa constantes
    difusor.PerdaCarga(fluido, bcs);
    difusor.Informacoes();

    /// Define fator de atrico e calcula perda de carga
    disco.Fator(fluido);
    disco.PerdaCarga(fluido,bcs);

    /// Calcula perda de carga rotor e informa constantes
    rotor.PerdaCarga(fluido,bcs);
    rotor.Informacoes();

    /// Calcula fator choque e perda de carga choque
    choque.Fator(fluido);
    choque.PerdaCarga (bcs);

    recirculacao.Informacoes();
    recirculacao.PerdaCarga();

    /// Calcula a perda de carga total
    PerdaCargaTotal();

    cout<<"Vazao (bbl/d)"<<setw(15)<<"Head teorico (m)"<<setw(15)<<"Altura de elevacao (m)\n";

     for (int i = 0; i<10; i++){
        alturaElevacao[i] = headTeorico[i] - perdaCargaSegmento[i];}

    fstream fout; ///< Salvar resultados da tabela em arquivo
    fout.open("resultados.txt", ios::out);
    fout.clear();
    fout << "Vazao (bbl/d)" <<setw(13) << "Head teorico (m)" <<setw(13) << "Altura de elevacao (m)\n";
    for (int i = 0; i<10; i++){

    fout <<setw(15)<<bcs.vazaoBPD[i]<<setw(15)<< headTeorico[i]<<setw(15)<<alturaElevacao[i]<<setw(15)<< "\n";}
    fout.close();

    for (int i = 0; i<10; i++){

    cout << bcs.vazaoBPD[i] << setw(16) << headTeorico[i] << setw(16) << alturaElevacao[i]<<"\n";}
}



void CSimuladorESPPerformance::PlotarResultado(){

    static CGnuplot plotar1;
    static CGnuplot plotar2;

         plotar1 << "set term png\n";
         plotar1 << "set out \"HeadTeorico_x_Vazao.png\"\n";
         plotar1.set_style("lines");
         plotar1.set_title("HeadTeorico_x_Vazao");
         plotar1.set_xlabel("vazao (bbl/d)");
         plotar1.set_ylabel("Head Teorico (m)");
         plotar1.Grid();
         plotar1.plotfile_xy("resultados.txt", 1,2);

         plotar2 << "set term png\n";
         plotar2 << "set out \"AlturaElevacao_x_Vazao.png\"\n";
         plotar2.set_style("lines");
         plotar2.set_title("AlturaElevacao_x_Vazao");
         plotar2.set_xlabel("vazao (bbl/d)");
         plotar2.set_ylabel("Altura Elevacao (m)");
         plotar2.Grid();
         plotar2.plotfile_xy("resultados.txt", 1,3);
}
