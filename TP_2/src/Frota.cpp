#include "Frota.h"


using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1){
	(this->veiculos).push_back(v1);
}

int Frota::numVeiculos() const{
	return (int) veiculos.size();
}
int Frota::menorAno() const{

	int temp = veiculos.at(0)->getAno();
	for(int i =1;i < veiculos.size();i++){

		if(veiculos.at(i)->getAno() < temp){
			temp = veiculos.at(i)->getAno();
		}

	}
	return temp;
}
