#pragma once
#include "Territorio.h"

class Ilha : public Territorio {
public:
	Ilha();
	Ilha(string, int, int, int);
	~Ilha();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
	
};
