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
	void ler_cmd(std::string);
	void inicia();
	void conquistar_passar();
	void recolha_produtos_ouro();
	void compra_unidades();
	void occorencia_evento();
	void termina_turno();
	std::vector<std::string> stringSplit(const std::string str_to_split, const std::string delimiter);
};
