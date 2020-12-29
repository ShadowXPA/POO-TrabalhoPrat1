#pragma once

#include "Continente.h"

class Montanha : public Continente {
public:
	Montanha();
	~Montanha();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
};
