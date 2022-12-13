#include <iostream>
#include "Pessoa.h"
#include <exception>

//inicializa a variavel estatica
int Pessoa::_id_geral = 400;

Pessoa::Pessoa(int salario){
    _id = _id_geral++; //incrementa o contador da variavel estatistica e define como ID da pessoa
    _salario = salario;
}

Pessoa::~Pessoa(){};

int Pessoa::get_salario()
{
    return _salario; //retorna o salario
};

int Pessoa::get_id()
{
    return _id; //retonar o id
};