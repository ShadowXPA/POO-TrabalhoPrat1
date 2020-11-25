#pragma once
#include "Territorio_Inicial.h"
#include "Imperio_Jogador.h"

class Mundo {
private:
	Imperio_Jogador *imperio;
	vector<Territorio *> territorios;
public:
	Mundo();
	~Mundo();
	void adicionar_territorio(Territorio *);
	void conquistar_territorio(const string);
	void mostra_territorios_imperio();
	void mostra_territorios_nao_conquistados();
};
