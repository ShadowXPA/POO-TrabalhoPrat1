#include "Recurso_Abandonado.h"
#include "Imperio_Jogador.h"

Recurso_Abandonado::Recurso_Abandonado() : Evento("RecursoAbandonado", "Um recurso abandonado foi encontrado e fornece recursos ao imperio.") {}

Recurso_Abandonado::~Recurso_Abandonado() {}

void Recurso_Abandonado::efeito(Imperio_Jogador *const imp, const float ano) {
	Evento::efeito(imp, ano);
	if (ano == 1.0f) {
		imp->incrementa_armazem();
	} else if (ano == 2.0f) {
		imp->incrementa_cofre();
	}
}
