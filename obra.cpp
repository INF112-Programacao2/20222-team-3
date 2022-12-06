#include "Obra.h"

int Obra::_id_geral=100;

Obra::Obra(std::string nome)
{
    _id=_id_geral++;
    _arquivada=false;
    _nome=nome;
}

int Obra::get_id(){
    return _id;
}
std::string Obra::get_nome(){
    return _nome;
}
bool Obra::get_arquivada(){
    return _arquivada;
}
void Obra::set_arquivada(bool arquivada){
    _arquivada=arquivada;
}
Obra::~Obra()
{};