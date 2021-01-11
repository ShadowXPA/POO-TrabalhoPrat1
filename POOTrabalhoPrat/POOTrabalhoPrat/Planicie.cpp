#include "Planicie.h"

Planicie::Planicie() : Continente("Planicie", 5, 1, 1) {}

Planicie::Planicie(Planicie &ter) : Continente(ter) {}

Planicie::~Planicie() {}

void Planicie::set_criacao_produtos(int) {}

void Planicie::set_criacao_ouro(int) {}

Territorio *Planicie::novo() {
    return new Planicie(*this);
}
