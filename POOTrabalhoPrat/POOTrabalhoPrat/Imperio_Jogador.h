#pragma once

#include "Territorio.h"
#include "Territorio_Inicial.h"
#include "Tecnologia.h"
#include "Ilha.h"
#include <vector>
#include <typeinfo>
#include <random>
#include <iostream>

class Imperio_Jogador {
private:
	std::vector<Territorio *> territorios_conquistados;
	std::vector<Tecnologia *> tecnologias;
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
	bool maisprod();
	int get_cofre();
	bool maisouro();
	void decrementar_cofre(int);
	int get_forca_militar();
	bool maismilitar();
	int get_fator_sorte();
	int gerar_fator_sorte(int = 1, int = 6);
	size_t tamanho_territorios_conquistados();
	bool pode_conquistar_ilha();
	void adicionar_territorio_conquistado(Territorio *);
	void adicionar_territorio_inicial(Territorio_Inicial *);
	void mostra_territorios_conquistados();
	bool encontra_territorio(Territorio *);
};
