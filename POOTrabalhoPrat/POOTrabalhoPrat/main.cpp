#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Jogo.h"

int main(int argc, char *argv[], char **envp) {
	Jogo *jogo = new Jogo();

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
