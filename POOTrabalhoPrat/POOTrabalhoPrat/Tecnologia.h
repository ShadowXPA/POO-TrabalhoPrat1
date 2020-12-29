#pragma once

#include <string>
#include "Imperio_Jogador.h"

class Tecnologia {
private:
	std::string nome;
	std::string objetivo;
	int custo;
	bool adquirido;
public:
	Tecnologia(std::string, std::string, int);
	~Tecnologia();
	std::string get_nome();
	std::string get_objetivo();
	int get_custo();
	bool ja_adquirido();
	virtual bool comprar(Imperio_Jogador &);
};
