#pragma once

#include "Mundo.h"
#include "Castelo.h"
#include "Duna.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Montanha.h"
#include "Planicie.h"
#include "Ilha.h"
#include "Pescaria.h"
#include "Refugio_Piratas.h"
#include <algorithm>
#include <random>
#include <time.h>
#include <fstream>

class Jogo {
private:
	Mundo *mundo;
	int turno;
	int pontuacao;
	bool jogo_a_correr;
	int fase;
	/*void cmd_cria(const string, const int);
	void cmd_conquista(const string);
	void cmd_carrega(const string);
	void cmd_lista(const string);*/
public:
	Jogo();
	~Jogo();
	Mundo *const get_mundo();
	void adicionar_territorio(Territorio *ter);
	void conquistar_territorio(string territorio);
	void mostra_territorio(std::string territorio);
	void mostra_territorios_imperio();
	void mostra_territorios_nao_conquistados();
	float get_ano();
	int get_turno();
	int get_fator_sorte();
	bool &get_jogo_a_correr();
	void incrementa_fase();
	/*void ler_cmd(string);
	void inicia();*/
	void conquistar_passar();
	void recolha_produtos_ouro();
	void compra_unidades();
	void occorencia_evento();
	void termina_turno();
};
