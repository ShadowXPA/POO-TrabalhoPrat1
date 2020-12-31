#include "Jogo.h"

using namespace std;

Jogo::Jogo() {
	srand((unsigned int) time(nullptr));
	this->turno = 0;
	this->pontuacao = 0;
	this->fase = -1;
	this->jogo_a_correr = true;
	this->mundo = new Mundo();
	this->mundo->adicionar_territorio_inicial(new Territorio_Inicial());
}

Jogo::~Jogo() {
	delete this->mundo;
}

Mundo *const Jogo::get_mundo() {
	return this->mundo;
}

void Jogo::adicionar_territorio(Territorio *ter) {
	this->mundo->adicionar_territorio(ter);
}

bool Jogo::conquistar_territorio(string territorio) {
	return this->mundo->conquistar_territorio(territorio);
}

void Jogo::mostra_territorio(string territorio) {
	this->mundo->mostra_territorio(territorio);
}

void Jogo::mostra_territorios_imperio() {
	this->mundo->mostra_territorios_imperio();
}

void Jogo::mostra_territorios_nao_conquistados() {
	this->mundo->mostra_territorios_nao_conquistados();
}

float Jogo::get_ano() {
	return turno / 6.0f;
}

int Jogo::get_turno() {
	return this->turno;
}

int Jogo::get_fator_sorte() {
	return this->mundo->get_fator_sorte();
}

int Jogo::get_fase()
{
	return this->fase;
}

bool &Jogo::get_jogo_a_correr() {
	return this->jogo_a_correr;
}

void Jogo::incrementa_fase() {
	this->fase = ++this->fase % 5;
}

void Jogo::conquistar_passar() {}

void Jogo::recolha_produtos_ouro() {}

void Jogo::compra_unidades() {}

void Jogo::occorencia_evento() {}

void Jogo::termina_turno() {}


/*
void Jogo::ler_cmd(string comando) {
	transform(comando.begin(), comando.end(), comando.begin(), ::tolower);
	auto str = stringSplit(comando, " ");
	if (str[0].compare("sair") == 0) {
		this->jogo_a_correr = false;
	} else if (str[0].compare("cria") == 0) {
		if (str.size() < 3)
			return;
		cmd_cria(str[1], stoi(str[2]));
	} else if (str[0].compare("conquista") == 0) {
		if (str.size() < 2)
			return;
		cmd_conquista(str[1]);
	} else if (str[0].compare("carrega") == 0) {
		if (str.size() < 2)
			return;
		cmd_carrega(str[1]);
	} else if (str[0].compare("lista") == 0) {
		if (str.size() < 2)
			cmd_lista("");
		else
			cmd_lista(str[1]);
	}
}

void Jogo::inicia() {
	ler_cmd("carrega Territorios.txt");
}


vector<string> Jogo::stringSplit(const string str_to_split, const string delimiter) {
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
}*/
