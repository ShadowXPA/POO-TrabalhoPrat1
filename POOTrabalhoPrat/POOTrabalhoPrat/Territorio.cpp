#include "Territorio.h"

Territorio::Territorio(string Nome) {
	this->Nome = Nome;
}

Territorio::Territorio(string Nome, int Resistencia, int Pontos_vitoria, int Criacao_produtos, int Criacao_ouro) {
	this->Nome = Nome;
	this->Pontos_Vitoria = Pontos_Vitoria;
	this->Criacao_produtos = Criacao_produtos;
	this->Criacao_ouro = Criacao_ouro;
}