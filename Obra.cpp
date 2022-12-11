#include "Obra.h"

int Obra::_id_geral = 100;

Obra::Obra(std::string nome) // metodo construtor
{
    _id = _id_geral++;
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
Obra::~Obra() // metodo destrutor
    {};