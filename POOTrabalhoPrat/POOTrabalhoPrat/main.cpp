#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Jogo.h"
#include "Controlador_Interface.h"

int main(int argc, char *argv[], char **envp) {
	//Jogo *jogo = new Jogo();
	Controlador_Interface *controlador_interface = new Controlador_Interface();
	// TODO
	// Tecnologias -> fazer a parte do comprar
	// Retirar typeid, fazer com que cada território "ser_conquistado"
	controlador_interface->inicia();

	//jogo->inicia();
	/*while (jogo->get_jogo_a_correr()) {
		string str="";
		cout << "\nIntroduza o comando que deseja: ";
		getline(cin, str);
		jogo->ler_cmd(str);
	}*/
	// jogo.inicia(); // ler ficheiro
	// while...
	//fase:
	// jogo.conquistar_passar();
	// jogo.recolha_produtos_ouro();
	// jogo.compra_unidades();
	// jogo.occorencia_evento();
	// jogo.termina_turno();
	// fim while...

	delete controlador_interface;
	return 0;
}
