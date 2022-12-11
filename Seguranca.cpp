#include <iostream>
#include "Seguranca.h"

Seguranca::Seguranca(bool horario_noturno,std::string carga_horaria,float salario):Funcionario(carga_horaria,salario)
{
    
    _horario_noturno = horario_noturno;
};

Seguranca::~Seguranca()
{
}

bool Seguranca::get_horario_noturno()
{

    return _horario_noturno;
}

float Seguranca::calcular_salario()
{

   
}