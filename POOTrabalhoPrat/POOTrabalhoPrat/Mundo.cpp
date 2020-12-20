#include "Mundo.h"

Mundo::Mundo() {
	this->imperio = new Imperio_Jogador();
}

Mundo::~Mundo() {
	delete this->imperio;
	for (int i = 0; i < this->territorios.size(); i++) {
		delete this->territorios[i];
	}
	this->territorios.clear();
}

int Mundo::get_fator_sorte() {
	return this->imperio->get_fator_sorte();
}

void Mundo::adicionar_territorio_inicial(Territorio *ter) {
	this->imperio->adicionar_territorio_inicial(ter);
	this->adicionar_territorio(ter);
}

void Mundo::adicionar_territorio(Territorio *ter) {
	this->territorios.push_back(ter);
}

void Mundo::conquistar_territorio(string nome) {
	Territorio_Inicial *ti = new Territorio_Inicial();
	string aux;
	for (int i = 0; i < this->territorios.size(); i++) {
		aux = this->territorios[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (aux.compare(nome) == 0) {
			if (typeid(this->territorios[i]) != typeid(*ti)) {
				this->imperio->adicionar_territorio_conquistado(this->territorios[i]);
			}
			break;
		}
	}
	delete ti;
}

void Mundo::mostra_territorios_imperio() {
	this->imperio->mostra_territorios_conquistados();
}

void Mundo::mostra_territorios_nao_conquistados() {
	for (int i = 0; i < this->territorios.size(); i++) {
		auto it = this->imperio->encontra_territorio(this->territorios[i]);
		if (!it) {
			cout << "\nNome: " << this->territorios[i]->get_nome();
			cout << "\nResistencia: " << this->territorios[i]->get_resistencia();
			cout << "\nProducao de produtos: " << this->territorios[i]->get_criacao_produtos();
			cout << "\nProducao de ouro: " << this->territorios[i]->get_criacao_ouro();
			cout << "\n------------------";
		}
	}
}

void Mundo::mostra_territorio(string nome_territorio)
{
	string aux;
	for (int i = 0; i < this->territorios.size(); i++) {
		aux = this->territorios[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (nome_territorio.compare(aux) == 0) {
			cout << "\nNome: " << this->territorios[i]->get_nome();
			cout << "\nPontos de Vitoria: " << this->territorios[i]->get_pontos_vitoria();
			cout << "\nResistencia: " << this->territorios[i]->get_resistencia();
			cout << "\nCriacao de Produtos: " << this->territorios[i]->get_criacao_produtos();
			cout << "\nCriacao de Ouro: " << this->territorios[i]->get_criacao_ouro();
			break;
		}
	}
}
