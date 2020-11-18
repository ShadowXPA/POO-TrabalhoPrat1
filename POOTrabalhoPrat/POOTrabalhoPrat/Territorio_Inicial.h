#pragma once
using namespace std;
#include "Territorio.h"


class Territorio_Inicial
{
	protected:
		string Nome = "";
		int Resistencia = 0;
		int Pontos_Vitoria = 0;
		int Criacao_produtos = 0;
		int Criacao_ouro = 0;
	public:
		Territorio_Inicial(string Nome, int Resistencia, int Pontos_vitoria, int Criacao_produtos, int Criacao_ouro);
};

