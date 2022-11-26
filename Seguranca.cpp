#include <iostream>
#include "Seguranca.h"

Seguranca::Seguranca()
{
    int a;
    std::cin >> a;
    horario_noturno = a;
};

Seguranca::~Seguranca()
{
}

bool Seguranca::get_horario_noturno()
{

    return horario_noturno;
}

float Seguranca::calcular_salario()
{

    float a;
    std::cin >> a;
    return a;
}