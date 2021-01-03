#include "Tecnologia.h"
#include "Imperio_Jogador.h"

using namespace std;

Tecnologia::Tecnologia(string nome, string objetivo, int custo) {
	this->nome = nome;
	this->objetivo = objetivo;
	this->custo = custo;
	this->adquirido = false;
}

Tecnologia::~Tecnologia() {}

string Tecnologia::get_nome() {
	return string(this->nome);
}

int Tecnologia::get_custo() {
	return this->custo;
}

string Tecnologia::get_objetivo() {
	return string(this->objetivo);
}

bool Tecnologia::ja_adquirido() {
	return this->adquirido;
}

bool Tecnologia::comprar(Imperio_Jogador &imp) {
	if (!this->adquirido && imp.get_cofre() >= this->custo) {
		imp.decrementar_cofre(this->custo);
		this->adquirido = true;
		return true;
	}
	return false;
}
