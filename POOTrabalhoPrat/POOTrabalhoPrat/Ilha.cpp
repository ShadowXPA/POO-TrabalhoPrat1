#include "Ilha.h"

using namespace std;

Ilha::Ilha(string nome, int resistencia, int criacao_produtos, int criacao_ouro) : Territorio(nome, 2, resistencia, criacao_produtos, criacao_ouro) {
	unsigned int static s_count = 0;
	s_count++;
	this->nome += to_string(s_count);
}

Ilha::~Ilha() {}

bool Ilha::ser_conquistado(Imperio_Jogador &imp) {
	// Verificar se tem as tecnologias necessárias
	// Proceder à conquista caso seja possível conquistar
	return false;
}
