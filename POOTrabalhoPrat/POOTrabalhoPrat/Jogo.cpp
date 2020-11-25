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

void Jogo::cmd_carrega(const string nome_fich) {
	ifstream File(nome_fich);
	string Line;
	if (File.is_open()) {
		while (getline(File, Line)) {
			this->ler_cmd(Line);
			cout << Line;
		}
		File.close();
	}
	cout << "Erro ao carregar o ficheiro!\n";
}

void Jogo::cmd_lista(const string nome){
	if (nome == "") {
		cout << "Ano: " << this->get_ano();
		cout << "\nTurno: " << this->get_turno();
		cout << "\nUltimo fator sorte gerado: " ;//TODO adicionar o ultimo fator de sorte
		cout << "\nTerritorios conquistados:";
		this->mundo->mostra_territorios_imperio();
		this->mundo->mostra_territorios_nao_conquistados();
		//TODO
		//Produtos (valor em armazém, valor máximo, produção no turno atual)
		//Ouro(valor em armazém, valor máximo, produção no turno atual)
		//Força militar(valor atual, valor máximo)
		//Tecnologias existentes(nome, preço, resumo do objetivo, adquirida / não adquirida)
		//Evento que vai ocorrer(nome, resumo dos efeitos)
		//Pontuação final
	}
	else {

	}
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
		if (str.size() < 3)
			return;
		cmd_cria(str[1], stoi(str[2]));
	} else if (str[0] == "conquista") {
		if (str.size() < 2)
			return;
		cmd_conquista(str[1]);
	} else if (str[0] == "carrega") {
		if (str.size() < 2)
			return;
		cmd_carrega(str[1]);
	} else if (str[0] == "lista") {
		if (str.size() < 2)
			cmd_lista("");
		cmd_lista(str[1]);
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
