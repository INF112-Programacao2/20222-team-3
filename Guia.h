#pragma once

#include <iostream>
#include <string>
#include "Funcionario.h"

class Guia : public Funcionario
{
private:
    // Dados privados
    bool _acessibilidade;
    int _especialidade;

public:
    // Construtor
    Guia(bool acessibilidade, int especialidade, std::string carga_horaria, float salario);
    // Destrutor
    virtual ~Guia();
    // Métodos

    bool get_acessibilidade();
    int get_especialidade();
    float calcular_salario();
};