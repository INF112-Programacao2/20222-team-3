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
    Guia(int salario,std::string carga_horaria,bool acessibilidade,int especialidade);
    // Destrutor
    virtual ~Guia();
    // Métodos

    bool get_acessibilidade();
    int get_especialidade();
    int calcular_salario();
};