#include "Controlador_Interface.h"

using namespace std;

Controlador_Interface::Controlador_Interface() {
	this->jogo = new Jogo();
}

Controlador_Interface::~Controlador_Interface() {
	delete this->jogo;
}

void Controlador_Interface::cmd_cria(string tipo, const int n) {
	transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
	for (int i = 0; i < n; i++) {
		if (tipo.compare("castelo") == 0) {
			this->jogo->adicionar_territorio(new Castelo());
		} else if (tipo.compare("duna") == 0) {
			this->jogo->adicionar_territorio(new Duna());
		} else if (tipo.compare("forteleza") == 0) {
			this->jogo->adicionar_territorio(new Fortaleza());
		} else if (tipo.compare("mina") == 0) {
			this->jogo->adicionar_territorio(new Mina());
		} else if (tipo.compare("montanha") == 0) {
			this->jogo->adicionar_territorio(new Montanha());
		} else if (tipo.compare("planicie") == 0) {
			this->jogo->adicionar_territorio(new Planicie());
		} else if (tipo.compare("pescaria") == 0) {
			this->jogo->adicionar_territorio(new Pescaria());
		} else if (tipo.compare("refugiopiratas") == 0) {
			this->jogo->adicionar_territorio(new Refugio_Piratas());
		} else {
			break;
		}
	}
}

void Controlador_Interface::cmd_conquista(const string nome) {
	// TODO mostrar resultado
	this->jogo->conquistar_territorio(nome);
}

void Controlador_Interface::cmd_carrega(const string nome_fich) {
	ifstream File(nome_fich);
	string Line;
	if (File.is_open()) {
		while (getline(File, Line)) {
			this->ler_cmd(Line);
			cout << Line << endl;
		}
		File.close();
	} else
		cout << "Erro ao carregar o ficheiro!\n";
}

void Controlador_Interface::cmd_lista(const string nome) {
	if (nome.compare("") == 0) {
		cout << "Ano: " << this->jogo->get_ano();
		cout << "\nTurno: " << this->jogo->get_turno();
		cout << "\nUltimo fator sorte gerado: " << this->jogo->get_fator_sorte();
		cout << "\n------------------";
		cout << "\nTerritorios conquistados:";
		this->jogo->mostra_territorios_imperio();
		cout << "\nTerritorios nao conquistados:";
		this->jogo->mostra_territorios_nao_conquistados();
		//TODO
		//Produtos (valor em armazém, valor máximo, produção no turno atual)
		//Ouro(valor em armazém, valor máximo, produção no turno atual)
		//Força militar(valor atual, valor máximo)
		//Tecnologias existentes(nome, preço, resumo do objetivo, adquirida / não adquirida)
		//Evento que vai ocorrer(nome, resumo dos efeitos)
		//Pontuação final
	} else {
		this->jogo->mostra_territorio(nome);
	}
}

void Controlador_Interface::cmd_passa() {
	this->jogo->incrementa_fase();
}

void Controlador_Interface::cmd_maisouro() {
	if (this->jogo->get_mundo()->get_imperio()->maisouro()) {
		cout << "Comando maisouro efetuado com sucesso!";
	} else {
		cout << "\nImpossivel obter mais ouro pois nao tem pelo menos 2 produtos!\n";
	}
}

void Controlador_Interface::cmd_maisprod() {
	if (this->jogo->get_mundo()->get_imperio()->maisprod()) {
		cout << "Comando maisprod efetuado com sucesso!";
	} else {
		cout << "\nImpossivel obter mais produtos pois nao tem pelo menos 2 ouro!\n";
	}
}

void Controlador_Interface::cmd_maismilitar() {
	if (this->jogo->get_mundo()->get_imperio()->maismilitar()) {
		cout << "Comando maismilitar efetuado com sucesso!";
	} else {
		cout << "\nImpossivel obter mais militar pois nao tem pelo menos 1 ouro e 1 produto!\n";
	}
}

void Controlador_Interface::cmd_adquire(const string tipo) {
		bool adquirido = this->jogo->get_mundo()->get_imperio()->pode_adquirir(tipo);
		//TODO
		if (adquirido) {
			cout << "Comando aquire efetuado com sucesso!";
		}
		else {
			cout << "\nImpossivel aquirir a tecnologia que desejava!\n";
		}
}

void Controlador_Interface::cmd_avanca() {
	this->jogo->incrementa_fase();
}

void Controlador_Interface::cmd_grava(const std::string)
{
}

void Controlador_Interface::cmd_ativa(const std::string)
{
}

void Controlador_Interface::cmd_apaga(const std::string)
{
}

void Controlador_Interface::cmd_toma(const std::string, const std::string)
{
}

void Controlador_Interface::cmd_modifica(const std::string, const int)
{
}

void Controlador_Interface::cmd_fevento(const std::string)
{
}

void Controlador_Interface::ler_cmd(string comando) {
	transform(comando.begin(), comando.end(), comando.begin(), ::tolower);
	auto str = stringSplit(comando, " ");
	int fase = this->jogo->get_fase();
	if (str[0].compare("sair") == 0) {
		this->jogo->get_jogo_a_correr() = false;
	} else if (str[0].compare("cria") == 0) {
		if (fase == -1) {
			if (str.size() < 3)
				return;
			cmd_cria(str[1], stoi(str[2]));
		}
	} else if (str[0].compare("conquista") == 0) {
		if (fase == 0) {
			if (str.size() < 2)
				return;
			cmd_conquista(str[1]);
		}
	} else if (str[0].compare("carrega") == 0) {
		if (fase == -1) {
			if (str.size() < 2)
				return;
			cmd_carrega(str[1]);
		}
	} else if (str[0].compare("lista") == 0) {
		if (str.size() < 2)
			cmd_lista("");
		else
			cmd_lista(str[1]);
	} else if (str[0].compare("passa") == 0) {
		if (fase == 0)
			cmd_passa();
	} else if (str[0].compare("maisouro") == 0) {
		if (fase == 1) {
			cmd_maisouro();
		}
	} else if (str[0].compare("maisprod") == 0) {
		if (fase == 1) {
			cmd_maisprod();
		}
	} else if (str[0].compare("maismilitar") == 0) {
		if (fase == 2) {
			cmd_maismilitar();
		}
	} else if (str[0].compare("adquire") == 0) {
		if (fase == 2) {
			if (str.size() < 2)
				return;
			cmd_adquire(str[1]);
		}
	} else if (str[0].compare("avanca") == 0) {
		cmd_avanca();
	} else if (str[0].compare("grava") == 0) {
		if (str.size() < 2)
			return;
		cmd_grava(str[1]);
	} else if (str[0].compare("ativa") == 0) {
		if (str.size() < 2)
			return;
		cmd_ativa(str[1]);
	} else if (str[0].compare("apaga") == 0) {
		if (str.size() < 2)
			return;
		cmd_apaga(str[1]);
	} else if (str[0].compare("toma") == 0) {
		if (str.size() < 3)
			return;
		cmd_toma(str[1], str[2]);
	} else if (str[0].compare("modifica") == 0) {
		if (str.size() < 3)
			return;
		cmd_modifica(str[1], stoi(str[2]));
	} else if (str[0].compare("fevento") == 0) {
		if (str.size() < 2)
			return;
		cmd_fevento(str[1]);
	}
}

void Controlador_Interface::inicia() {
	this->ler_cmd("carrega Territorios.txt");
	//algo para controlar as fases....
	while (this->jogo->get_jogo_a_correr()) {
		string str = "";
		cout << "\nIntroduza o comando que deseja: ";
		getline(cin, str);
		this->ler_cmd(str);
	}
}

vector<string> Controlador_Interface::stringSplit(const string str_to_split, const string delimiter) {
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
