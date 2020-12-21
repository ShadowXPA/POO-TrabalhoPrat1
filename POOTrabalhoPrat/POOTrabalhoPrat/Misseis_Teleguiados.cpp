#include "Misseis_Teleguiados.h"

Misseis_Teleguiados::Misseis_Teleguiados() : Tecnologia("Misseis Teleguiados", "Esta tecnologia e necessaria para conquistar ilhas.", 4) {}

Misseis_Teleguiados::~Misseis_Teleguiados() {}

bool Misseis_Teleguiados::comprar(Imperio_Jogador &imp) {
	return Tecnologia::comprar(imp);
}
