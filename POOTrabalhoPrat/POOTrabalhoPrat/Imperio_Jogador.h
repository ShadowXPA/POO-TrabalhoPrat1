#pragma once
#include "Territorio.h"
#include "Tecnologia.h"
#include "Ilha.h"
#include <vector>
#include <typeinfo>
#include <random>
#include <iostream>

class Imperio_Jogador {
private:
	vector<Territorio *> territorios_conquistados;
	Tecnologia *tecnologias;
	int armazem;
	//criar getter e setter para max´s
	int max_armazem;
	int cofre;
	int max_cofre;
	int forca_militar;
	int max_forca_militar;
	int fator_sorte;
public:
	Imperio_Jogador();
	~Imperio_Jogador();
	int get_armazem();
	int get_cofre();
	void decrementar_cofre(int);
	int get_forca_militar();
	int get_fator_sorte();
	size_t tamanho_territorios_conquistados();
	bool pode_conquistar_ilha();
	void adicionar_territorio_conquistado(Territorio *);
	void adicionar_territorio_inicial(Territorio *);
	void mostra_territorios_conquistados();
	bool encontra_territorio(Territorio *);
};
