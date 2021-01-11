#include "Castelo.h"

Castelo::Castelo() : Continente("Castelo", 7, 3, 1) {}

Castelo::Castelo(Castelo &ter) : Continente(ter) {}

Castelo::~Castelo() {}

void Castelo::set_criacao_produtos(int) {}

void Castelo::set_criacao_ouro(int) {}

Territorio *Castelo::novo() {
    return new Castelo(*this);
}
