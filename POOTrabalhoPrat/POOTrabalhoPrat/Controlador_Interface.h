#pragma once
#include "Jogo.h"

class Controlador_Interface
{
private:
	Jogo* jogo;
public:
	Controlador_Interface();
	~Controlador_Interface();
	void cmd_cria(const string, const int);
	void cmd_conquista(const string);
	void cmd_carrega(const string);
	void cmd_lista(const string);
	void ler_cmd(string);
	void inicia();
	void conquistar_passar();
	void recolha_produtos_ouro();
	void compra_unidades();
	void occorencia_evento();
	void termina_turno();
	vector<string> stringSplit(const string str_to_split, const string delimiter);
};

