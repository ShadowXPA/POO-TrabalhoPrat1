#pragma once

#include <string>
#include "Imperio_Jogador.h"

using namespace std;

class Tecnologia {
private:
	string nome;
	string objetivo;
	int custo;
	bool adquirido;
public:
	Tecnologia(string, string, int);
	~Tecnologia();
	string get_nome();
	string get_objetivo();
	int get_custo();
	bool ja_adquirido();
	virtual bool comprar(Imperio_Jogador &);
};
