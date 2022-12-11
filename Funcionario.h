#pragma once
#include "Pessoa.h"
#include <iostream>

class Funcionario : public Pessoa
{

private:
    // Dados privados
    std::string _carga_horaria;

public:
    // Construtor
    Funcionario(int salario,std::string carga_horaria);
    // Destrutor
    virtual ~Funcionario();

    // Métodos
    std::string get_carga_horaria();
    // Interface
    virtual int calcular_salario() = 0;
};