#pragma once

class Tecnologia {
private:
	const int DRONES_MILITARES = 3;
	const int MISSEIS_TELEGUIADOS = 4;
	const int DEFESAS_TERRITORIAIS = 4;
	const int BOLSA_VALORES = 2;
	const int BANCO_CENTRAL = 0;
	bool drones_militares;
	bool misseis_teleguiados;
	bool defesas_territoriais;
	bool bolsa_valores;
	bool banco_central;
public:
	Tecnologia();
	~Tecnologia();
	bool get_drones_militares();
	bool get_misseis_teleguiados();
	bool get_defesas_territoriais();
	bool get_bolsa_valores();
	bool get_banco_central();
	int get_custo_drones_militares();
	int get_custo_misseis_teleguiados();
	int get_custo_defesas_territoriais();
	int get_custo_bolsa_valores();
	int get_custo_banco_central();
	bool comprar_drones_militares(int&);
	bool comprar_misseis_teleguiados(int&);
	bool comprar_defesas_territoriais(int&);
	bool comprar_bolsa_valores(int&);
	bool comprar_banco_central(int&);
};
