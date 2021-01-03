#include "Alianca_Diplomatica.h"
#include "Imperio_Jogador.h"

using namespace std;

Alianca_Diplomatica::Alianca_Diplomatica() : Evento("AliancaDiplomatica", "E assinada uma alianca com outro imperio. Em consequencia disto a forca militar aumenta uma unidade.") {}

Alianca_Diplomatica::~Alianca_Diplomatica() {}

void Alianca_Diplomatica::efeito(Imperio_Jogador *const imp, const float ano) {
	// Efeito causado pela aliança
	Evento::efeito(imp, ano);
	imp->incrementa_militar();
}
