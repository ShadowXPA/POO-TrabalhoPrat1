#pragma once

#include "Continente.h"

class Planicie : public Continente {
public:
	Planicie();
	~Planicie();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
};
