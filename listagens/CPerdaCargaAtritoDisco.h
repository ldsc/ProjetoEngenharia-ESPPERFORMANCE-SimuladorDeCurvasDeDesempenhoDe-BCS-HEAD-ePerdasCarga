#ifndef CPERDACARGAATRITODISCO_H
#define CPERDACARGAATRITODISCO_H

#include <map>
#include "CPerdaCarga.h"

/// Classe que realiza o calculo da perda de carga por atrito de disco.

class CPerdaCargaAtritoDisco: public CPerdaCarga
{
    public:
        double fatorAtrito;///< fator empirico para o calculo da perda de carga por atrito de disco

    public:
        CPerdaCargaAtritoDisco(){};
        virtual ~CPerdaCargaAtritoDisco(){};

        std::map<double,double> mFatorAtrito; ///< map que associa a viscodade a fator empirico de perda por atrito de disco, a pertir de tabela em arquivo externo

        double PerdaCarga (CFluido& fluido, CBombaBCS& bcs);///< metodo para calcular a perda de carga por atrito de disco
        double  Fator(CFluido& fluido);///< metodo para definir qual dos fatores de atrito será aplicado ao calculo da perda de carga em funcao da viscosidade

       

};
#endif // CPERDACARGAATRITODISCO_H
