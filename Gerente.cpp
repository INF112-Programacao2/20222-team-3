#include "Gerente.h"
Gerente::Gerente(int ID, double salario, Exposicao *exposicoes):
    Usuario(ID, 0), _exposicoes(*exposicoes) {};
void Gerente::get_exposicoes(){
    return _exposicoes;
}
Gerente::~Gerente()
{};