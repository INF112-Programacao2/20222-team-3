#pragma once
#include "Pessoa.h"
#include <iostream>

class Funcionario : public Pessoa
{

private:
    std::string _carga_horaria;

public:
    Funcionario(std::string carga_horario, int id, float salario);
    ~Funcionario();

    std::string get_carga_horaria();

    virtual float calcular_salario() = 0;
};