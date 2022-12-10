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
    Guia(bool acessibilidade, int especialidade, std::string carga_horaria, int id, float salario);
    // Destrutor
    ~Guia();
    // Métodos

    bool get_acessibilidade();
    int get_especialidade();
    float calcular_salario();
};