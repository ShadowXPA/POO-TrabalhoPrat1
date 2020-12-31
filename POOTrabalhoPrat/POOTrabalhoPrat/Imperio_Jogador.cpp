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
	this->tecnologias.push_back(new Banco_Central());
	this->tecnologias.push_back(new Bolsa_Valores());
	this->tecnologias.push_back(new Defesas_Territoriais());
	this->tecnologias.push_back(new Drones_Militares());
	this->tecnologias.push_back(new Misseis_Teleguiados());
}

Imperio_Jogador::~Imperio_Jogador() {
	for (int i = 0; i < this->tecnologias.size(); i++) {
		delete this->tecnologias[i];
	}
}

int Imperio_Jogador::get_armazem() {
	return this->armazem;
}

bool Imperio_Jogador::maisprod() {
	if (this->cofre >= 2 && incrementa_armazem()) {
		this->cofre -= 2;
		return true;
	}
	return false;
}

bool Imperio_Jogador::incrementa_armazem(int i) {
	if (this->armazem + i <= this->max_armazem) {
		this->armazem += i;
		return true;
	}
	return false;
}

int Imperio_Jogador::get_cofre() {
	return this->cofre;
}

bool Imperio_Jogador::maisouro() {
	if (this->armazem >= 2 && incrementa_cofre()) {
		this->armazem -= 2;
		return true;
	}
	return false;
}

bool Imperio_Jogador::incrementa_cofre(int i) {
	if (this->cofre + i <= this->max_cofre) {
		this->cofre += i;
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

bool Imperio_Jogador::maismilitar() {
	if (this->armazem >= 1 && this->cofre >= 1 && incrementa_militar()) {
		this->armazem--;
		this->cofre--;
		return true;
	}
	return false;
}

bool Imperio_Jogador::incrementa_militar(int i) {
	if (this->forca_militar + i <= this->max_forca_militar) {
		this->forca_militar += i;
		return true;
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


bool Imperio_Jogador::pode_adquirir(std::string tipo)
{
	string aux;
	for (int i = 0; i < this->tecnologias.size(); i++) {
		aux = this->tecnologias[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (aux.compare(tipo) == 0) {
			return this->tecnologias[i]->comprar(*this);
		}
	}
	return false;
}

bool Imperio_Jogador::adquiriu_tecnologia(std::string tecnologia) {
	string aux;
	for (int i = 0; i < this->tecnologias.size(); i++) {
		aux = this->tecnologias[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (aux.compare(tecnologia) == 0) {
			return this->tecnologias[i]->ja_adquirido();
		}
	}
	return false;
}

bool Imperio_Jogador::adicionar_territorio_conquistado(Territorio *ter) {
	this->fator_sorte = this->gerar_fator_sorte();
	this->fator_sorte += this->forca_militar;

	if (this->fator_sorte >= ter->get_resistencia()) {
		if (!this->encontra_territorio(ter)) {
			this->territorios_conquistados.push_back(ter);
			return true;
		}
	} else {
		this->forca_militar -= (this->forca_militar <= 1) ? 0 : 1;
	}
	return false;
}

bool Imperio_Jogador::territorio_invadido(const int fator_sorte) {
	int offset = this->territorios_conquistados.size() - 1;
	Territorio *ter = this->territorios_conquistados[offset];
	int res = ter->get_resistencia();
	res += adquiriu_tecnologia("defesasterritoriais") ? 1 : 0;
	if (fator_sorte < res)
		return false;
	this->territorios_conquistados.erase(this->territorios_conquistados.begin() + offset);
	return true;
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
