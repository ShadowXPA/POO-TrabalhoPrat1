#include "Bolsa_Valores.h"

Bolsa_Valores::Bolsa_Valores() : Tecnologia("Bolsa de valores", "Sistema comercial que torna possivel as trocas entre produtos e ouro.", 2) {}

Bolsa_Valores::~Bolsa_Valores() {}

bool Bolsa_Valores::comprar(Imperio_Jogador &imp) {
	return Tecnologia::comprar(imp);
}
