#pragma once
#include "Continente.h"

class Mina : public Continente {
public:
	Mina();
	~Mina();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
};
