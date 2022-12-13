#pragma once

#include <iostream>
#include <string>
#include "Funcionario.h"

class Guia : public Funcionario
{
private:
    bool _acessibilidade; // define se o guia e capacitado para fazer acecssibilidade
    int _especialidade;   // define o nivel de especializacao do guia

public:
    Guia(int salario, std::string carga_horaria, bool acessibilidade, int especialidade);
    virtual ~Guia();
    bool get_acessibilidade(); // retorna se o guia e capacitado
    int get_especialidade();   // retorna a espcialidade
    int calcular_salario();    // calcula o salario
};