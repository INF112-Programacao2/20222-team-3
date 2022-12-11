#include <iostream>
#include "Seguranca.h"
#include <iostream>
#include <algorithm>
#include <exception>

Seguranca::Seguranca(bool horario_noturno, std::string carga_horaria, int salario) : Funcionario(carga_horaria, salario) // Construtor de Funcionário
{

    _horario_noturno = horario_noturno;
    //Tratando exceção caso seja inserido um valor diferente de um valor lógico válido.
    if(_horario_noturno != 0 || _horario_noturno != 1)
    throw std::invalid_argument("Horario Noturno só recebe true(1) ou false(0)!\n");
};

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