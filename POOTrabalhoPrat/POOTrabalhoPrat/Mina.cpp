#include "Mina.h"

Mina::Mina() : Continente("Mina", 5, 0, 1) {}

Mina::Mina(Mina &ter) : Continente(ter) {}

Mina::~Mina() {}

void Mina::set_criacao_produtos(int) {}

void Mina::set_criacao_ouro(int) {}

Territorio *Mina::novo() {
    return new Mina(*this);
}
