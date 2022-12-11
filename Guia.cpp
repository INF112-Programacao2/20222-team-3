#include <iostream>
#include <string>
#include "Guia.h"
#include <algorithm>

Guia::Guia(bool acessibilidade, int especialidade, std::string carga_horaria, float salario) : Funcionario(carga_horaria, salario) // Construtor de Funcionario
{
    _acessibilidade = acessibilidade;
    _especialidade = especialidade;
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

float Guia::calcular_salario()
{
    // uma variavel temporaria com o valor de vezes em que ele trabalhou na semana
    int i = count(get_carga_horaria().begin(), get_carga_horaria().end(), '1');
    // salario base X a quantidade de dias por semana que ele trabalha X 4 semanas(mês)
    return get_salario() * i * 4;
};
