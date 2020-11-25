#include "Imperio_Jogador.h"

Imperio_Jogador::Imperio_Jogador() {
	this->tecnologias = 0b00000000;
	this->armazem = 0;
	this->cofre = 0;
	this->forca_militar = 0;
}

Imperio_Jogador::~Imperio_Jogador() {}

int Imperio_Jogador::tamanho_territorios_conquistados() {
	return this->territorios_conquistados.size();
}

bool Imperio_Jogador::pode_conquistar_ilha() {
	return ((this->tamanho_territorios_conquistados() >= 5) && (this->tecnologias & this->MISSEIS_TELEGUIADOS));
}

void Imperio_Jogador::adicionar_territorio_conquistado(Territorio *ter) {
	Ilha *il = nullptr;
	bool pode_conquistar = false;
	int fator_sorte = (rand() % 6) + 1;
	fator_sorte += this->forca_militar;

	if (fator_sorte >= ter->get_resistencia()) {
		if (typeid(*ter) != typeid(*il) || (typeid(*ter) == typeid(*il) && this->pode_conquistar_ilha())) {
			pode_conquistar = true;
		}
		if (pode_conquistar) {
			this->territorios_conquistados.push_back(ter);
		}
	} else {
		this->forca_militar -= (this->forca_militar <= 1) ? 0 : 1;
	}
}
