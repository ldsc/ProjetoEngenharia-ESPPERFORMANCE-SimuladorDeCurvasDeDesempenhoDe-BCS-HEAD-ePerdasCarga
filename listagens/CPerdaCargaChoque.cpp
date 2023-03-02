#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>

#include "CPerdaCargaChoque.h"

using namespace std;

double CPerdaCargaChoque::Fator(CFluido& fluido){


    ifstream in ("fatorChoque.txt");
      in.ignore(256, '\n');
      while (!in.eof()){
      	  double viscosidade;
      	  double fatCho;
      	  in>> viscosidade;
		  in>> fatCho;
		  mFatorChoque.insert(make_pair(viscosidade, fatCho));
		  }
      in.close();

      if (mFatorChoque.find(fluido.viscosidade) != mFatorChoque.end()) {
      map<double,double>::const_iterator iter;
      iter = mFatorChoque.find(fluido.viscosidade);
      fatorChoque=iter->second;}

      cout<<"\n";
      cout<<"O fator de perda por choque empirico e: "<<fatorChoque;
      cout<<"\n";

	}

double CPerdaCargaChoque::PerdaCarga(CBombaBCS& bcs){
    for (int i = 0; i < pc.size(); i++){
            pc [i] = fatorChoque*(pow(bcs.vazao[i]- bcs.vazaoBEP,2));
        }

}


