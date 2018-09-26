#include "Parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli): lotacao(lot), numMaximoClientes(nMaxCli),vagas(lot) {
	this->vagas=lotacao;

}

unsigned int ParqueEstacionamento::getNumLugares() const{
return lotacao;
}
unsigned int ParqueEstacionamento::getNumMaximoClientes() const{
	return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const{
	for(unsigned int i = 0;i < clientes.size();i++){
		if(nome==clientes.at(i).nome){
			return (int) i;
		}
	}
	return -1;

}
bool ParqueEstacionamento::adicionaCliente(const string & nome){
	int temp =posicaoCliente(nome);
	if(clientes.size()!=numMaximoClientes){
		if(temp ==-1){
		InfoCartao cartao;
		cartao.nome=nome;
		cartao.presente=false;
		clientes.push_back(cartao);
		return true;
		}
	}
	else return false;
}

bool ParqueEstacionamento::entrar(const string & nome){
	int indice = posicaoCliente(nome);
	if(indice == -1){
		return false;
	}
	if(clientes.at(indice).presente == true){
		return false;
	}
	if(vagas==0){
		return false;
	}
	clientes.at(indice).presente=true;
	vagas--;
	return true;
}


bool ParqueEstacionamento::retiraCliente(const string & nome){

	int indice = posicaoCliente(nome);
	if(indice ==-1){
		return false;
	}
	if (clientes.at(indice).presente == false){
		clientes.erase(clientes.begin()+indice);
		return true;
	}
	else{
		return false;
	}
}


bool ParqueEstacionamento::sair(const string & nome){
	int indice = posicaoCliente(nome);
	if(indice == -1){
		return false;
	}
	else if(clientes.at(indice).presente == false){
		return false;
	}
	else{
		clientes.at(indice).presente = false;
		vagas++;
		return true;
	}

}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const{
	return (lotacao - vagas);
}
unsigned int ParqueEstacionamento::getNumClientesAtuais() const{
	return clientes.size();
}
