#pragma once

#include "Territorio.h"

class Continente : public Territorio {
public:
	Continente(std::string, int, int, int);
	~Continente();
	virtual bool ser_conquistado(Imperio_Jogador &) override;
};
