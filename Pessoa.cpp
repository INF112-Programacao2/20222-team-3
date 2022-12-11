#include <iostream>
#include "Pessoa.h"
// Id Geral é uma variavel estatica
int Pessoa::_id_geral = 400;
// Construtor
Pessoa::Pessoa(float salario)
{
    // sempre que uma pessoa é criada o id geral incrementa 1 em id geral;
    _id = _id_geral++;
    _salario = salario;
}
// Destrutor
Pessoa::~Pessoa(){};
// Métodos
float Pessoa::get_salario()
{
    // Retorna o valor do salario(base)
    return _salario;
};
int Pessoa::get_id()
{
    // retorna o id
    return _id;
};