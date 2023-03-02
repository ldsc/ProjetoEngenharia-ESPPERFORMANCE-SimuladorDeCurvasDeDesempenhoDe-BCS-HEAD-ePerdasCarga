#ifndef CPERDACARGAATRITOROTOR_H
#define CPERDACARGAATRITOROTOR_H

#include "CPerdaCarga.h"

/// Classe que realiza o calculo da perda de carga por atrito no rotor.

class CPerdaCargaAtritoRotor: public CPerdaCarga
{
    public:
        CPerdaCargaAtritoRotor(){};
        virtual ~CPerdaCargaAtritoRotor(){};

        /// Metodo para calcular a perda de carga
        double PerdaCarga (CFluido& fluido, CBombaBCS& bcs);

        void Informacoes ();///< metodo para informar as constantes presentes na formulacao da perda por atrito no rotor (Sun e Prado, 2003)
};
#endif // CPERDACARGAATRITOROTOR_H
