#include "Montanha.h"

Montanha::Montanha() : Continente("Montanha", 5, 1, 1) {}

Montanha::Montanha(Montanha &ter) : Continente(ter) {}

Montanha::~Montanha() {}

void Montanha::set_criacao_produtos(int) {}

void Montanha::set_criacao_ouro(int) {}

Territorio *Montanha::novo() {
    return new Montanha(*this);
}
