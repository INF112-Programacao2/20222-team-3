#include <iostream>
#include <string>
#include "Guia.h"
#include <algorithm>
#include <ctype.h>

Guia::Guia(int salario,std::string carga_horaria,bool acessibilidade,int especialidade):
    Funcionario(salario,carga_horaria), _acessibilidade(acessibilidade), _especialidade(especialidade){}

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
