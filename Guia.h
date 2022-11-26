#pragma once

#include <iostream>
#include <string>
#include "Funcionario.h"

class Guia : public Funcionario
{
private:
    // Dados privados
    std::string funcao;
    std::string especialidade;

public:
    // Construtor
    Guia();
    // Destrutor
    ~Guia();
    // Métodos

    void get_funcao();
    void get_especialidade();
    float calcular_salario();
};