#include "Veiculo.h"


using namespace std;

Veiculo::Veiculo(string mc, int m, int a) {
	this->marca = mc;
	this->mes = m;
	this->ano = a;

}
string Veiculo::getMarca()const {

	return marca;
}
int Veiculo::getAno() const{
	return ano;
}


Motorizado::Motorizado(string mc, int m, int a,string c,int cil): Veiculo(mc,m,a) {
	this->combustivel = c;
	this->cilindrada = cil;

}
string Motorizado::getCombustivel() const{

	return combustivel;
}

Automovel::Automovel(string mc, int m, int a,string c, int cil):Motorizado(mc,m,a,c,cil){}

Camiao::Camiao(string mc, int m, int a,string c, int cil,int cm):Motorizado(mc,m,a,c,cil){
	this->carga_maxima=cm;
}

Bicicleta::Bicicleta(string mc, int m, int a,string t): Veiculo(mc,m,a){
	this->tipo =t;

}
