#pragma once
#include "Pessoa.h"
#include <iostream>
#include <string>

class Funcionario : public Pessoa
{

private:
    std::string _carga_horaria; // string de 0s e 1s indicando se o funcionario trabalha naquele dia

public:
    Funcionario(int salario, std::string carga_horaria);
    virtual ~Funcionario();

    std::string get_carga_horaria();    // retorna a carga horaria
    virtual int calcular_salario() = 0; // usado para calcular o salario, implementado nas classes derivadas
};