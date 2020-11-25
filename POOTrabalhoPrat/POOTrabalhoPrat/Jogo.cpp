#include "Jogo.h"

void Jogo::cmd_cria(string tipo, const int n) {
	transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
	for (int i = 0; i < n; i++) {
		if (tipo == "castelo") {
			this->mundo->adicionar_territorio(new Castelo());
		} else if (tipo == "duna") {
			this->mundo->adicionar_territorio(new Duna());
		} else if (tipo == "forteleza") {
			this->mundo->adicionar_territorio(new Fortaleza());
		} else if (tipo == "mina") {
			this->mundo->adicionar_territorio(new Mina());
		} else if (tipo == "montanha") {
			this->mundo->adicionar_territorio(new Montanha());
		} else if (tipo == "planicie") {
			this->mundo->adicionar_territorio(new Planicie());
		} else if (tipo == "pescaria") {
			this->mundo->adicionar_territorio(new Pescaria());
		} else if (tipo == "refugiopiratas") {
			this->mundo->adicionar_territorio(new Refugio_Piratas());
		} else {
			break;
		}
	}
}

void Jogo::cmd_conquista(const string nome) {
	this->mundo->conquistar_territorio(nome);
}

Jogo::Jogo() {
	srand(time(nullptr));
	this->turno = 0;
	this->pontuacao = 0;
	this->mundo = new Mundo();
	this->mundo->adicionar_territorio(new Territorio_Inicial());
}

Jogo::~Jogo() {
	delete this->mundo;
	this->mundo = nullptr;
}

float Jogo::get_ano() {
	return turno / 6.0f;
}

int Jogo::get_turno() {
	return this->turno;
}

void Jogo::ler_cmd(string comando) {
	transform(comando.begin(), comando.end(), comando.begin(), ::tolower);
	auto str = stringSplit(comando, " ");
	if (str[0] == "cria") {
		if (str.size() != 3)
			return;
		cmd_cria(str[1], stoi(str[2]));
	} else if (str[0] == "conquista") {
		if (str.size() != 2)
			return;
		cmd_conquista(str[1]);
	}
}

vector<string> stringSplit(const string str_to_split, const string delimiter) {
	vector<string> list;
	string str(str_to_split);
	size_t position = 0;
	string token;
	while ((position = str.find(delimiter)) != string::npos) {
		token = str.substr(0, position);
		list.push_back(token);
		str.erase(0, position + delimiter.length());
	}
	list.push_back(str);
	return list;
}
