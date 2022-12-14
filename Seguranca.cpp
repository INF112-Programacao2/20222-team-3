#include "Seguranca.h"
#include <iostream>
#include <exception>

Seguranca::Seguranca(int salario,std::string carga_horaria,bool horario_noturno):
    Funcionario(salario,carga_horaria), _horario_noturno(horario_noturno){}

Seguranca::~Seguranca()
{};

bool Seguranca::get_horario_noturno()
{
    // retorna se ele trabalha a noite ou não
    return _horario_noturno;
}

int Seguranca::calcular_salario()
{
    // Quantidade de dias trabalhados (respresentado por '1')
    int cont=0;
    for(int i=0;i<get_carga_horaria().size();i++)
        if(get_carga_horaria()[i]=='1') //se a posicao da sttring e 1 ele trabalha naquele dia
            cont++; //incrementa contador
    if (_horario_noturno)
        // se o segurança trabalha a noite, ele ganha um adicional
        return get_salario() * cont * 4 + 300;
    else
        return get_salario() * cont * 4;
}