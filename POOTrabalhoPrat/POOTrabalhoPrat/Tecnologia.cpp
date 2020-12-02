#include "Tecnologia.h"

Tecnologia::Tecnologia() {
	this->drones_militares = false;
	this->misseis_teleguiados = false;
	this->defesas_territoriais = false;
	this->bolsa_valores = false;
	this->banco_central = false;
}

Tecnologia::~Tecnologia() {}

bool Tecnologia::get_drones_militares() {
	return this->drones_militares;
}

bool Tecnologia::get_misseis_teleguiados() {
	return this->misseis_teleguiados;
}

bool Tecnologia::get_defesas_territoriais() {
	return this->defesas_territoriais;
}

bool Tecnologia::get_bolsa_valores() {
	return this->bolsa_valores;
}

bool Tecnologia::get_banco_central() {
	return this->banco_central;
}

int Tecnologia::get_custo_drones_militares() {
	return this->DRONES_MILITARES;
}

int Tecnologia::get_custo_misseis_teleguiados() {
	return this->MISSEIS_TELEGUIADOS;
}

int Tecnologia::get_custo_defesas_territoriais() {
	return this->DEFESAS_TERRITORIAIS;
}

int Tecnologia::get_custo_bolsa_valores() {
	return this->BOLSA_VALORES;
}

int Tecnologia::get_custo_banco_central() {
	return this->BANCO_CENTRAL;
}

bool Tecnologia::comprar_drones_militares(int &ouro) {
	if (ouro >= this->DRONES_MILITARES) {
		ouro -= this->DRONES_MILITARES;
		this->drones_militares = true;
		return true;
	}
	return false;
}

bool Tecnologia::comprar_misseis_teleguiados(int &ouro) {
	if (ouro >= this->MISSEIS_TELEGUIADOS) {
		ouro -= this->MISSEIS_TELEGUIADOS;
		this->misseis_teleguiados = true;
		return true;
	}
	return false;
}

bool Tecnologia::comprar_defesas_territoriais(int &ouro) {
	if (ouro >= this->DEFESAS_TERRITORIAIS) {
		ouro -= this->DEFESAS_TERRITORIAIS;
		this->defesas_territoriais = true;
		return true;
	}
	return false;
}

bool Tecnologia::comprar_bolsa_valores(int &ouro) {
	if (ouro >= this->BOLSA_VALORES) {
		ouro -= this->BOLSA_VALORES;
		this->bolsa_valores = true;
		return true;
	}
	return false;
}

bool Tecnologia::comprar_banco_central(int &ouro) {
	if (ouro >= this->BANCO_CENTRAL) {
		ouro -= this->BANCO_CENTRAL;
		this->banco_central = true;
		return true;
	}
	return false;
}
