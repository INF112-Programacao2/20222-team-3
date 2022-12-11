#include <iostream>
#include "Pessoa.h"
#include <exception>
// Id Geral é uma variavel estatica
int Pessoa::_id_geral = 400;
// Construtor
Pessoa::Pessoa(int salario)
{
    // sempre que uma pessoa é criada o id geral incrementa 1 em id geral;
    _id = _id_geral++;
    _salario = salario;
    // Tratando exceção de salario (Caso insira algo diferente de um número)
    if (!isdigit(_salario))
        throw std::invalid_argument("Salário deve ser um inteiro");
}
// Destrutor
Pessoa::~Pessoa(){};
// Métodos
int Pessoa::get_salario()
{
    // Retorna o valor do salario(base)
    return _salario;
};
int Pessoa::get_id()
{
    // retorna o id
    return _id;
};