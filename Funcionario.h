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
    Funcionario(std::string carga_horario, float salario);
    // Destrutor
    virtual ~Funcionario();

    // Métodos
    std::string get_carga_horaria();
    // Interface
    virtual float calcular_salario() = 0;
};