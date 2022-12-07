#pragma once
#include "Pessoa.h"
#include <iostream>

class Funcionario : public Pessoa
{

private:
    bool *carga_horaria;

public:
    Funcionario();
    ~Funcionario();

    void get_carga_horaria();

    virtual float calcular_salario() = 0;
};