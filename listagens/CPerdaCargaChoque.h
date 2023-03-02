#ifndef CPERDACARGACHOQUE_H
#define CPERDACARGACHOQUE_H

#include "CPerdaCarga.h"
#include <map>

/// Classe que realiza o calculo da perda de carga por atrito de choque

class CPerdaCargaChoque: public CPerdaCarga
{
    public:
        CPerdaCargaChoque(){};
        virtual ~CPerdaCargaChoque(){};

        std::map<double,double> mFatorChoque;///< map que associa a viscodade a fator empirico de perda por choque, a pertir de tabela em arquivo externo

        double fatorChoque;///< fator empirico para o calculo da perda de carga por choques no rotor

        double PerdaCarga (CBombaBCS& bcs);///< metodo para calcular a perda de carga por choques no rotor
        double Fator(CFluido& fluido);///< metodo para definir qual dos fatores de choque sera aplicado ao calculo da perda de carga em funcao da viscosidade
        };
#endif // CPERDACARGACHOQUE_H
