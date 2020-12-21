#include "Banco_Central.h"

Banco_Central::Banco_Central() : Tecnologia("Banco Central", "Esta tecnologia permite aumentar em duas unidades a capacidade de armazenamento do armazem e do cofre do imperio.", 3) {}

Banco_Central::~Banco_Central() {}

bool Banco_Central::comprar(Imperio_Jogador &imp) {
	return Tecnologia::comprar(imp);
}
