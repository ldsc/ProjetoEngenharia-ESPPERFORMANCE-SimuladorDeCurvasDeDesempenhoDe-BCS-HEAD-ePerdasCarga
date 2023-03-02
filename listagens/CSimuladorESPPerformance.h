#ifndef CSIMULADORESPPERFORMANCE_H
#define CSIMULADORESPPERFORMANCE_H

#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>

#include "CFluido.h"
#include "CBombaBCS.h"
#include "CHeadTeorico.h"
#include "CPerdaCargaAtritoDifusor.h"
#include "CPerdaCargaAtritoDisco.h"
#include "CPerdaCargaAtritoRotor.h"
#include "CPerdaCargaChoque.h"
#include "CPerdaCargaRecirculacao.h"
#include "CGnuplot.h"

/// Classe simulador que gera os resultados, salva e plota os graficos

class CSimuladorESPPerformance
{
private:

    int numeroIntervalos; ///< Numero de intervalos usados nos calculos das perdas de carga.
public:
        std::vector <double> alturaElevacao; ///< altura de elevacao do BCS
        std::vector <double> perdaCargaSegmento;///< perda de carga segmento = soma de todas as perdas de carga
        CFluido fluido;
        CBombaBCS bcs;
        CHeadTeorico headTeorico;
        CPerdaCargaAtritoDifusor difusor;
        CPerdaCargaAtritoDisco disco;
        CPerdaCargaAtritoRotor rotor;
        CPerdaCargaChoque choque;
        CPerdaCargaRecirculacao recirculacao;

public:
       CSimuladorESPPerformance(){};
       virtual ~CSimuladorESPPerformance(){};

        void Menu(); ///< metodo que fornece opcoes viscosidade e rotacao para a simulacao e atribui os devidos parametros para os calculos de acordo com a combinacao escolhida
        double AlturaElevacao ();///< metodo para calculo e implementacao da equacao da altura de elevacao de bombas centrifugas, bem como gerar resultados em tabela
        void PerdaCargaTotal();///< metodo para o calculo do somatorio de todas as perdas de carga
        void PlotarResultado();///< metodo para plotar os resultados obtidos (Head teorico X vazao) e (altura de elevacao X vazao)

};
#endif // CSIMULADORESPPERFORMANCE_H

