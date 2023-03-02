#ifndef CPERDACARGARECIRCULACAO_H
#define CPERDACARGARECIRCULACAO_H

#include <vector>
#include "CPerdaCarga.h"

/// Classe que realiza o calculo da perda de carga por recirculacao.

class CPerdaCargaRecirculacao : public CPerdaCarga
{
    public:
        CPerdaCargaRecirculacao(){};
        virtual ~CPerdaCargaRecirculacao(){};

        double PerdaCarga();///< metodo para calcular a perda de carga por recirculacoes no rotor

        void Informacoes();
};
#endif // CPERDACARGARECIRCULACAO_H


