#include <iostream>
#include <string>
#include "Guia.h"
#include <algorithm>

Guia::Guia(bool acessibilidade, int especialidade, std::string carga_horaria, float salario) : Funcionario(carga_horaria, salario)
{
    _acessibilidade = acessibilidade;
    _especialidade = especialidade;
};

Guia::~Guia(){};

int Guia::get_especialidade()
{

    return _especialidade;
};
bool Guia::get_acessibilidade()
{
    return _acessibilidade;
};

float Guia::calcular_salario()
{

    int i = count(get_carga_horaria().begin(), get_carga_horaria().end(), '1');

    return get_salario() * i;
};
