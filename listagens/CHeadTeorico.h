#ifndef CHeadTeorico_H
#define CHeadTeorico_H

#include <vector>

#include "CBombaBCS.h"

/// Classe que calcula o head teorico (ou altura de elevacao teorica)

class CHeadTeorico
{
    public:
        ///atributos:
        std:: vector <double> hteorico;///< altura de elevacao teorica (ou head teorico) do BCS (m)
        double operator[](int i) { return hteorico[i]; } ;///< CHeadTeorico obj; obj[i]

    public:
        CHeadTeorico():hteorico(10){};               //construtor
        virtual ~CHeadTeorico(){};      // destrutor

        double AlturaTeorica (CBombaBCS& bcs);///< metodo que calcula o head teorico
        void Informacoes();///< metodo para informar as constantes presentes na formulacao do head teorico (Pfleiderer, 1972)
};
#endif // CHEADTEORICO_H


