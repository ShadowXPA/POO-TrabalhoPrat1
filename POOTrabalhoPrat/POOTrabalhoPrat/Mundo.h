#pragma once

#include "Territorio_Inicial.h"
#include "Imperio_Jogador.h"

class Mundo {
private:
	Imperio_Jogador *imperio;
	std::vector<Territorio *> territorios;
public:
	Mundo();
	~Mundo();
	Imperio_Jogador* const get_imperio();
	int get_fator_sorte();
	void adicionar_territorio_inicial(Territorio_Inicial *);
	void adicionar_territorio(Territorio *);
	bool conquistar_territorio(std::string);
	void mostra_territorios_imperio();
	void mostra_territorios_nao_conquistados();
	void mostra_territorio(std::string);
};
