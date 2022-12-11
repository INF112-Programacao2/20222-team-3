#include <iostream>
#include "Seguranca.h"
#include <iostream>
#include <algorithm>
#include <exception>

Seguranca::Seguranca(int salario,std::string carga_horaria,bool horario_noturno):
    Funcionario(salario,carga_horaria), _horario_noturno(horario_noturno){}

Seguranca::~Seguranca()
{
}

bool Seguranca::get_horario_noturno()
{
    // retorna se ele trabalha a noite ou não
    return _horario_noturno;
}

int Seguranca::calcular_salario()
{
    // Quantidade de dias trabalhados (respresentado por '1')
    int i = count(get_carga_horaria().begin(), get_carga_horaria().end(), '1');
    if (_horario_noturno)
        // se o segurança trabalha a noite, ele ganha o dobro
        return get_salario() * 2 * i * 4;
    else
        return get_salario() * i * 4;
}