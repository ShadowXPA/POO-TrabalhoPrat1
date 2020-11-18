#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Territorio.h"
#include "Mina.h"
#include "Montanha.h"
#include "Planicie.h"
#include "Fortaleza.h"
#include "Duna.h"
#include "Refugio_dos_Piratas.h"
#include "Pescaria.h"
#include "Castelo.h"

using namespace std;

void UploadFile(string File_Name);
void CreateTerritories(string Name_Territorie, int N_Territories);
void ConquerTerritories(string Territorie_To_Conquist);
void List(string str);


vector<string> stringSplit(string str_to_split, string delimiter);

int main(int argc, char* argv[], char** envp) {
	string Command = "";
	while (true) {
		cout << "Introduza o comando que deseja realizar: \n";
		cin >> Command;
		vector<string> strings = stringSplit(Command, " ");
		if (strings[0] == "carrega") {
			string File_Name = strings[1];
			UploadFile(File_Name);
		}
		else if (strings[0] == "cria") {
			string Name_Territorie = strings[1];
			string N_Territories = strings[2];
			int N_Terr = stoi(Name_Territorie);
			int n;
			CreateTerritories(Name_Territorie, N_Terr);
		}
		else if (strings[0] == "conquista") {
			string Territorie_To_Conquist = strings[1];
			ConquerTerritories(Territorie_To_Conquist);
		}
		else if (strings[0] == "lista") {
			string str = strings[1];
			List(str);
		}
	}
	return 0;
}

void UploadFile(string File_Name) {
	ifstream File(File_Name);
	string Line;
	if (File.is_open()) {
		while (getline(File, Line))
		{
			vector<string> strings = stringSplit(Line, " ");
			//Podemos usar a Funcao CreateTerritories se esta string for enviada com cuidado e dependendo do formato do ficheiro
			cout << Line << '\n';
		}
		File.close();
	}
	cout << "Erro ao carregar o ficheiro!\n";
}

void CreateTerritories(string Name_Territorie, int N_Territories) {
	int i = 0;
	while (N_Territories > 0)
	{
		//Tipo de territorio
		if (Name_Territorie == "mina") {
			Mina mina();
			N_Territories--;
		}
		else if (Name_Territorie == "montanha") {
			Montanha montanha();
			N_Territories--;
		}
		else if (Name_Territorie == "planicie") {
			Planicie planicie();
			N_Territories--;
		}else if (Name_Territorie == "fortaleza")
		{
			Fortaleza fortaleza();
			N_Territories--;
		}
		else if (Name_Territorie == "duna") {
			Duna duna();
			N_Territories--;
		}
		else if(Name_Territorie == "castelo"){
			Castelo castelo();
			N_Territories--;
		}
		else if (Name_Territorie == "refugio dos piratas") {
			Refugio_dos_Piratas refugio();
			N_Territories--;
		}
		else if (Name_Territorie == "pescaria") {
			Pescaria pescaria();
			N_Territories--;
		}
	}
}

void ConquerTerritories(string Territorie_To_Conquist) {
	//TODO Dá a ordem ao império para adquirir um determinado território
	//neste turno desde que este esteja disponível no Mundo.O parâmetro nome indica
	//qual o nome do território a conquistar(planicie1, duna3, etc.).
}

void List(string str) {
	//TODO Obtém a informação do jogo, tanto globalmente como apenas de um território específico caso o seu nome seja indicado como parâmetro.
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