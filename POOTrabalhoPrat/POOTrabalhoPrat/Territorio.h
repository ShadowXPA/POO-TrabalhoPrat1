#pragma once
#include <string>
using namespace std;

class Territorio {
	protected:
	string nome;
	int pontos_vitoria;
	int resistencia;
	int criacao_produtos;
	int criacao_ouro;
	public:
	Territorio(string, int, int, int, int);
	string get_nome();
	int get_pontos_vitoria();
	int get_resistencia();
	int get_criacao_produtos();
	int get_criacao_ouro();
	virtual void set_criacao_produtos(int) = 0;
	virtual void set_criacao_ouro(int) = 0;
};
