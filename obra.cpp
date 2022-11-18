#include "obra.h"


Obra::Obra(int id_obra_, bool arquivada_, std::string nome_obra_)
{
    id_obra=id_obra_;
    arquivada=arquivada_;
    nome_obra=nome_obra_;
}

int Obra::get_id_obra(){
    return id_obra;
}
std::string Obra::get_nome_obra(){
    return nome_obra;
}
bool Obra::get_arquivada(){
    return arquivada;
}
Obra::~Obra()
{};