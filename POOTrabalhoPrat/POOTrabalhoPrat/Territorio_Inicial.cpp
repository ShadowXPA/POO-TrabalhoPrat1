#include "Territorio_Inicial.h"
using namespace std;

Territorio_Inicial::Territorio_Inicial(string Nome, int Resistencia, int Pontos_vitoria, int Criacao_produtos, int Criacao_ouro) {
	this->Nome = Nome;
	this->Resistencia = 9;
	this->Pontos_Vitoria = 0;
	this->Criacao_produtos = 1;
	this->Criacao_ouro = 1;
}