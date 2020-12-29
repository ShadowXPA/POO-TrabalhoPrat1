#include "Imperio_Jogador.h"

using namespace std;

Imperio_Jogador::Imperio_Jogador() {
	this->armazem = 0;
	this->max_armazem = 3;
	this->cofre = 0;
	this->max_cofre = 3;
	this->forca_militar = 0;
	this->max_forca_militar = 3;
	this->fator_sorte = 0;
}

Imperio_Jogador::~Imperio_Jogador() {
	for (int i = 0; i < this->tecnologias.size(); i++) {
		delete this->tecnologias[i];
	}
}

int Imperio_Jogador::get_armazem() {
	return this->armazem;
}

bool Imperio_Jogador::maisprod()
{
	if (this->cofre >= 2 && this->armazem < this->max_armazem) {
		this->armazem++;
		this->cofre -= 2;
		return true;
	}
	return false;
}

int Imperio_Jogador::get_cofre() {
	return this->cofre;
}

bool Imperio_Jogador::maisouro()
{
	if (this->armazem >= 2 && this->cofre < this->max_cofre) {
		this->cofre++;
		this->armazem -= 2;
		return true;
	}
	return false;
}

void Imperio_Jogador::decrementar_cofre(int i) {
	this->cofre -= i;
	if (this->cofre < 0)
		this->cofre = 0;
}

int Imperio_Jogador::get_forca_militar() {
	return this->forca_militar;
}

bool Imperio_Jogador::maismilitar()
{
	if (this->armazem >= 1 && this->cofre >= 1 && this->forca_militar < this->max_forca_militar) {
		this->forca_militar++;
		this->armazem--;
		this->cofre--;
	}
	return false;
}

int Imperio_Jogador::get_fator_sorte() {
	return this->fator_sorte;
}

int Imperio_Jogador::gerar_fator_sorte(int min, int max) {
	return (rand() % max) + min;
}

size_t Imperio_Jogador::tamanho_territorios_conquistados() {
	return this->territorios_conquistados.size();
}

bool Imperio_Jogador::pode_conquistar_ilha() {
	return ((this->tamanho_territorios_conquistados() >= 5));
}

void Imperio_Jogador::adicionar_territorio_conquistado(Territorio *ter) {
	// TODO arranjar isto
	bool pode_conquistar = false;
	this->fator_sorte = this->gerar_fator_sorte();
	this->fator_sorte += this->forca_militar;

	if (this->fator_sorte >= ter->get_resistencia()) {
		if (!this->encontra_territorio(ter) && (this->pode_conquistar_ilha())) {
			pode_conquistar = true;
		}
		if (pode_conquistar) {
			this->territorios_conquistados.push_back(ter);
		}
	} else {
		this->forca_militar -= (this->forca_militar <= 1) ? 0 : 1;
	}
}

void Imperio_Jogador::adicionar_territorio_inicial(Territorio_Inicial *ter) {
	this->territorios_conquistados.push_back(ter);
}

void Imperio_Jogador::mostra_territorios_conquistados() {
	for (int i = 0; i < this->territorios_conquistados.size(); i++) {
		cout << "\nNome: " << this->territorios_conquistados[i]->get_nome();
		cout << "\nResistencia: " << this->territorios_conquistados[i]->get_resistencia();
		cout << "\nProducao de produtos: " << this->territorios_conquistados[i]->get_criacao_produtos();
		cout << "\nProducao de ouro: " << this->territorios_conquistados[i]->get_criacao_ouro();
		cout << "\n------------------";
	}
}

bool Imperio_Jogador::encontra_territorio(Territorio *ter) {
	for (int i = 0; i < this->territorios_conquistados.size(); i++) {
		if (ter == this->territorios_conquistados[i]) {
			return true;
		}
	}
	return false;
}
