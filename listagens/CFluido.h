#ifndef CFluido_H
#define CFluido_H

#include <iostream>
#include <vector>

///Classe fluido com os atributos referentes ao escoamento que sao inerentes ao fluido,viscosidade e massa especifica

class CFluido
{
    public:
    ///atributos fluido:
    double viscosidade{1};            ///< viscosidade do fluido (1 cP ou 270 cP)
    double massaEspecifica{997};        ///< tomadas como referencia as da agua (997 kg/m3) ou da glicerina (1260 kg/m3)

    /// Metodos
    CFluido(){};          // Construtor
    virtual ~CFluido(){}; // Destrutor
};
#endif
