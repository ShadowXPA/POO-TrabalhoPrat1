#pragma once

#include "Jogo.h"

class Controlador_Interface {
private:
	Jogo *jogo;
public:
	Controlador_Interface();
	~Controlador_Interface();
	void cmd_cria(const std::string, const int);
	void cmd_conquista(const std::string);
	void cmd_carrega(const std::string);
	void cmd_lista(const std::string);
	void cmd_passa();
	void cmd_maisouro();
	void cmd_maisprod();
	void cmd_maismilitar();
	void ler_cmd(std::string);
	void inicia();
	std::vector<string> stringSplit(const std::string str_to_split, const std::string delimiter);
};

