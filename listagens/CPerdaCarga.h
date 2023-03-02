#ifndef CPERDACARGA_H
#define CPERDACARGA_H

#include <vector>
#include "CFluido.h"
#include "CBombaBCS.h"

/// Classe base de perdas de cargas gerais que recebe fluido e bomba BCS
class CPerdaCarga
{
//     private:
//     CFluido& fluido;
//     CBombaBCS& bcs;
    
    public:
        std::vector<double>pc; ///< Vetor com a perda de carga por seguimento.
        double operator[](int i) { return pc[i]; } ///< retorna a perda de carga no segmento i
        
    public:
        /// Construtor, recebe fluido e bombabcs.
        //CPerdaCarga(CFluido& _fluido, CBombaBCS& _bcs)fluido(_fluido), bcs(_bcs){};
        CPerdaCarga():pc(10){};
        
        /// Destrutor
        virtual ~CPerdaCarga(){};

        /// Método para calcular a perda de carga 
        double PerdaCarga (CFluido& fluido, CBombaBCS& bcs) {return 0.0;};

        /// Método para calcular a perda de carga 
        double PerdaCarga () {return 0.0;};

        // Informacoes sobre equacoes e parametros utilizados
        void Informacoes() {};
};
#endif // CPERDACARGA_H
