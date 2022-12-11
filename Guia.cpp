#include <iostream>
#include <string>
#include "Guia.h"

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
    int cont = 0;


    
};
