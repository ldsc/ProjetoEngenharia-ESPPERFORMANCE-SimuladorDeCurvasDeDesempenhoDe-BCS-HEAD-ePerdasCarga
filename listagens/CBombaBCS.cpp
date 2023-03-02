#include "CBombaBCS.h"

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

double CBombaBCS::ConverteVazao(){

	ifstream fin ("vazao.txt"); ///< abre arquivo com valores de vazao

    /// preenche vetor vazao
    double v;
    vazao.clear(); ///< zera vetor de vazao

    fin.ignore(256, '\n'); ///< ignora a primeira linha

    while (!fin.eof()) {
        fin >> v;
        vazao.push_back(v);
       }

    fin.close(); ///< fecha arquivo de dados

	vazaoBPD.resize(10);

	for (int i = 0; i<vazao.size(); i++) {
		vazaoBPD[i] = vazao[i] * 543456; ///< conversao de vazao para saida dos resultados
		vazaoBPD.push_back(i);
	}
}



