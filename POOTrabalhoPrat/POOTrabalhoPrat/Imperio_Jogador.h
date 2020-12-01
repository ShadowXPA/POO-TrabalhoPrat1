#pragma once
#include "Territorio.h"
#include "Ilha.h"
#include <vector>
#include <typeinfo>
#include <random>
#include <iostream>

class Imperio_Jogador {
private:
	const int DRONES_MILITARES = 1;
	const int MISSEIS_TELEGUIADOS = 2;
	const int DEFESAS_TERRITORIAIS = 4;
	const int BOLSA_VALORES = 8;
	const int BANCO_CENTRAL = 16;
	vector<Territorio *> territorios_conquistados;
	int tecnologias;
	int armazem;
	int cofre;
	int forca_militar;
	int fator_sorte;
public:
	Imperio_Jogador();
	~Imperio_Jogador();
	int get_armazem();
	int get_cofre();
	int get_forca_militar();
	int get_fator_sorte();
	size_t tamanho_territorios_conquistados();
	bool pode_conquistar_ilha();
	void adicionar_territorio_conquistado(Territorio *);
	void adicionar_territorio_inicial(Territorio *);
	void mostra_territorios_conquistados();
	bool encontra_territorio(Territorio *);
};
