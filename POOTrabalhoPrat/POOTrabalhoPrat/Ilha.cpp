#include "Ilha.h"

Ilha::Ilha() : Territorio("", 0, 0,0,0){}

Ilha::Ilha(string nome, int resistencia, int criacao_produtos, int criacao_ouro) : Territorio(nome, 2, resistencia, criacao_produtos, criacao_ouro) {
	unsigned int static s_count = 0;
	s_count++;
	this->nome += to_string(s_count);
}

Ilha::~Ilha() {}

void Ilha::set_criacao_produtos(int){}

void Ilha::set_criacao_ouro(int){}
