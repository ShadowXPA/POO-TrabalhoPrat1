#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Jogo.h"

int main(int argc, char *argv[], char **envp) {
	Jogo *jogo = new Jogo();

	// TODO: Conquistar mesmo território não deve ser possível
	// Cada tecnologia ser uma class derivada de Tecnologia
	// Tirar o = nullptr
	// Retirar typeid, fazer com que cada território "ser_conquistado"
	//criar uma classe que lide com a interface

	jogo->inicia();
	while (jogo->get_jogo_a_correr()) {
		string str="";
		cout << "\nIntroduza o comando que deseja: ";
		getline(cin, str);
		jogo->ler_cmd(str);
	}
	// jogo.inicia(); // ler ficheiro
	// while...
	//fase:
	// jogo.conquistar_passar();
	// jogo.recolha_produtos_ouro();
	// jogo.compra_unidades();
	// jogo.occorencia_evento();
	// jogo.termina_turno();
	// fim while...

	delete jogo;
	jogo = nullptr;

	return 0;
}
