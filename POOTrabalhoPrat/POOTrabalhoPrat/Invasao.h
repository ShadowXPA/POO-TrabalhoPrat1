#pragma once

#include "Evento.h"

class Invasao : public Evento {
private:

public:
	Invasao();
	~Invasao();
	void efeito(Imperio_Jogador *const, const int) override;
};
