#ifndef CPERDACARGAATRITODIFUSOR_H
#define CPERDACARGAATRITODIFUSOR_H

#include "CPerdaCarga.h"

/// Classe que realiza o calculo da perda de carga por atrito no difusor.

class CPerdaCargaAtritoDifusor : public CPerdaCarga
{
    public:
        CPerdaCargaAtritoDifusor(){};
        virtual ~CPerdaCargaAtritoDifusor(){};

        /// Metodo para calcular a perda de carga
        double PerdaCarga (CFluido& fluido, CBombaBCS& bcs);

        void Informacoes();///< metodo para informar as constantes presentes na formulacao da perda por atrito no difusor (Ito, 1959)
};

#endif // CPERDACARGAATRITODIFUSOR_H
