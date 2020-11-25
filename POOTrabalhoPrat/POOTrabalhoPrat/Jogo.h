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
	void cmd_cria(const string, const int);
	void cmd_conquista(const string);
	void cmd_carrega(const string);
	void cmd_lista(const string);
public:
	Jogo();
	~Jogo();
	float get_ano();
	int get_turno();
	void ler_cmd(string);
	void inicia();
	void conquistar_passar();
	void recolha_produtos_ouro();
	void compra_unidades();
	void occorencia_evento();
	void termina_turno();
	vector<string> stringSplit(const string str_to_split, const string delimiter);
};
