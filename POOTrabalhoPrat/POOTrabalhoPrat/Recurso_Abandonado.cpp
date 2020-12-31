#include "Recurso_Abandonado.h"

Recurso_Abandonado::Recurso_Abandonado() : Evento("RecursoAbandonado", "Um recurso abandonado foi encontrado e fornece recursos ao imperio.") {}

Recurso_Abandonado::~Recurso_Abandonado() {}

void Recurso_Abandonado::efeito(Imperio_Jogador *const imp, const int ano) {
	Evento::efeito(imp, ano);
	if (ano == 1) {
		imp->incrementa_armazem();
	} else if (ano == 2) {
		imp->incrementa_cofre();
	}
}
