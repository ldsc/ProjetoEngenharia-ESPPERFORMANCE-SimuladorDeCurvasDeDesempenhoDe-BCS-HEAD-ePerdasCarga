#ifndef CBombaBCS_H
#define CBombaBCS_H

#include <iostream>
#include <vector>

///Classe bomba BCS com os atributos referentes ao escoamento que sao inerentes ao BCS, rotacao e vazao, e que armazena as vazoes pre-definidas e faz as devidas conversoes de unidade

 class CBombaBCS
{
    public:
    /// atributos bomba:
    double rotacao;             ///< rotacao da bomba (1800 rpm ou 3500 rpm)
    std::vector <double> vazao; ///<vetor de vazoes (m3/s) como dados de entrada tomadas baseadas nos dados experimentais de Amaral (2007)
    double PreencheVazao ();
    int opcaoMenuRotacao;       ///< usuario escolhe qual das duas rotacoes disponiveis ira simular
    double vazaoBEP;            ///< vazao no ponto de melhor eficiencia para cada um dos 4 casos operacionais disponiveis
    std::vector <double> vazaoBPD; ///< vazao em barris por dia

    /// Metodos
    CBombaBCS(){};              // Construtor
    virtual ~CBombaBCS(){};     // Destrutor

    double ConverteVazao ();            ///< metodo para converter vazao de m3/s para bbl/d

};
#endif
