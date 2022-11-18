#include "Exposicao.h"

Exposicao::Exposicao(int semana, int ID, bool acessibilidade)
{
    _semana=semana;
    _ID=ID;
    _acessibilidade=acessibilidade;
}
void Exposicao::get_semana(){
    return _semana;
}
void Exposicao::get_ID(){
    return _ID;
}
void Exposicao::get_acessiblidade(){
    return _acessibilidade;
}
Exposicao::~Exposicao()
{};