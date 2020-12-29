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
	void cmd_passa();
	void cmd_maisouro();
	void cmd_maisprod();
	void cmd_maismilitar();
	void ler_cmd(string);
	void inicia();
	vector<string> stringSplit(const string str_to_split, const string delimiter);
};

