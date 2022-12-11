#include <iostream>
#include <string>
#include "Guia.h"
#include <algorithm>
#include <ctype.h>

Guia::Guia(bool acessibilidade, int especialidade, std::string carga_horaria, int salario) : Funcionario(carga_horaria, salario) // Construtor de Funcionario
{

    _acessibilidade = acessibilidade;
    _especialidade = especialidade;
    // Acessibilidade só pode receber valores lógicos(true e false), tratando exceção;
    if (_acessibilidade != 0 || _acessibilidade != 1)
        throw std::invalid_argument("Acessibilidade só recebe true(1) ou false(0)!\n");
    // Especialidade só recebe inteiro, tratando exceção
    if (!isdigit(_especialidade))
        throw std::invalid_argument("Especialidade só recebe inteiros");
    // Especialidade só recebe inteiros entre 1 e 5 , tratando exceções;

    if (_especialidade < 1 || _especialidade > 5)
        throw std::invalid_argument("Especialidade só pertimite inteiros entre 1 e 5");
};

Guia::~Guia(){};

int Guia::get_especialidade()
{
    // Retorna o valor da especialidade
    return _especialidade;
};
bool Guia::get_acessibilidade()
{ // Retorna se true ou false para acessibilidade
    return _acessibilidade;
};

int Guia::calcular_salario()
{
    // uma variavel temporaria com o valor de vezes em que ele trabalhou na semana
    int i = count(get_carga_horaria().begin(), get_carga_horaria().end(), '1');
    // salario base X a quantidade de dias por semana que ele trabalha X 4 semanas(mês)
    return get_salario() * i * 4;
};
