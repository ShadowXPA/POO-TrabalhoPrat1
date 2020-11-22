#pragma once
#include "Territorio.h"
#include "Territorio_Inicial.h"
#include "Imperio_Jogador.h"
#include <vector>

class Mundo {
	private:
	vector<Territorio*> territorios;
	Imperio_Jogador imperio;
	public:
	Mundo();
};
