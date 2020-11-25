#include "Mundo.h"

Mundo::Mundo() {
	this->imperio = new Imperio_Jogador();
}

Mundo::~Mundo() {
	delete this->imperio;
	this->imperio = nullptr;
	for (int i = 0; i < this->territorios.size(); i++) {
		delete this->territorios[i];
		this->territorios[i] = nullptr;
	}
	this->territorios.clear();
}

void Mundo::adicionar_territorio(Territorio *ter) {
	this->territorios.push_back(ter);
}

void Mundo::conquistar_territorio(const string nome) {
	Territorio_Inicial *ti = nullptr;
	for (int i = 0; i < this->territorios.size(); i++) {
		if (this->territorios[i]->get_nome() == nome) {
			if (typeid(this->territorios[i]) != typeid(*ti)) {
				this->imperio->adicionar_territorio_conquistado(this->territorios[i]);
			}
			break;
		}
	}
}

void Mundo::mostra_territorios_imperio() {
	this->imperio->mostra_territorios_conquistados();
}

void Mundo::mostra_territorios_nao_conquistados(){
	for (int i = 0; i < this->territorios.size(); i++) {
		auto it = this->imperio->encontra_territorio(this->territorios[i]);
		if (it == this->territorios.end()) {
			cout << "\nNome: " << this->territorios[i]->get_nome();
			cout << "\nResistencia: " << this->territorios[i]->get_resistencia();
			cout << "\nProducao de produtos: " << this->territorios[i]->get_criacao_produtos();
			cout << "\nProducao de ouro: " << this->territorios[i]->get_criacao_ouro();
		}
	}
}
