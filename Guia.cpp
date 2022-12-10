#include <iostream>
#include <string>
#include "Guia.h"

Guia::Guia(bool acessibilidade, int especialidade,std::string carga_horaria,int id,float salario): Funcionario(carga_horaria,id,salario)
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
    

    
};
