#pragma once

#include <string>
#include "Imperio_Jogador.h"

class Evento {
protected:
	std::string nome;
	std::string descricao;
public:
	Evento();
	Evento(std::string, std::string);
	~Evento();
	std::string get_nome();
	std::string get_descricao();
	virtual void efeito(Imperio_Jogador *const, const int);
};
