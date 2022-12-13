#include "Obra.h"

//inicializa a variavel estatica
int Obra::_id_geral = 100;

Obra::Obra(std::string nome)
{
    _id = _id_geral++; //incrementa o contador da variavel estatistica e define como ID da obra
    _arquivada = false;
    _nome = nome;
}

int Obra::get_id()
{ // retorna o id da obra
    return _id;
}
std::string Obra::get_nome()
{ // retorna o nome da obra
    return _nome;
}
bool Obra::get_arquivada()
{ // retorna um booleano se a obra esta arquivada ou nao
    return _arquivada;
}
void Obra::set_arquivada(bool arquivada)
{ // alteracao de arquivada
    _arquivada = arquivada;
}
Obra::~Obra()
{};