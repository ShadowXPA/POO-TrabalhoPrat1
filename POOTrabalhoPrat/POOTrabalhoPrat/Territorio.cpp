#include "Territorio.h"

Territorio::Territorio(string nome, int pontos_vitoria, int resistencia, int criacao_produtos, int criacao_ouro) {
	this->nome = nome;
	this->pontos_vitoria = pontos_vitoria;
	this->criacao_produtos = criacao_produtos;
	this->criacao_ouro = criacao_ouro;
}

Territorio::~Territorio()
{
}

string Territorio::get_nome() {
	return this->nome;
}

int Territorio::get_pontos_vitoria() {
	return this->pontos_vitoria;
}

int Territorio::get_resistencia() {
	return this->resistencia;
}

int Territorio::get_criacao_produtos() {
	return this->criacao_produtos;
}

int Territorio::get_criacao_ouro() {
	return this->criacao_ouro;
}
