#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>

#include "CPerdaCargaAtritoDisco.h"

using namespace std;

double CPerdaCargaAtritoDisco::Fator(CFluido& fluido){

      ifstream in ("fatorDisco.txt");
      in.ignore(256, '\n');
      while (!in.eof()){
          double viscosidade;
          double fatDis;
      	  in>> viscosidade;
		  in>> fatDis;
		  mFatorAtrito.insert(make_pair(viscosidade, fatDis));
		  }
      in.close();
      if (mFatorAtrito.find(fluido.viscosidade) != mFatorAtrito.end()) {
      map<double,double>::const_iterator iter;
      iter = mFatorAtrito.find(fluido.viscosidade);
      fatorAtrito=iter->second;}

      cout<<"\n";
      cout<<"O fator de atrito de disco empirico para esta opcao e: "<<fatorAtrito;
      cout<<"\n";

	}


double CPerdaCargaAtritoDisco::PerdaCarga (CFluido& fluido, CBombaBCS& bcs){
    for (int i = 0; i < pc.size(); i++){
        pc[i] = ((4.5917 * (pow (10,-17))) * fatorAtrito *fluido.massaEspecifica * (pow (bcs.rotacao,3)))/ (bcs.vazao[i]);
        //pc.push_back(i);
    }
}
