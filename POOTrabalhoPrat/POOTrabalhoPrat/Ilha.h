#pragma once

#include "Territorio.h"

class Ilha : public Territorio {
public:
	Ilha(std::string, int, int, int);
	~Ilha();
	virtual bool ser_conquistado(Imperio_Jogador &) override;
};
