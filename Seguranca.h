#pragma once
#include <string>
#include "Funcionario.h"

class Seguranca : public Funcionario
{
private:
    bool _horario_noturno; // define se o seguranca trabalha a noite

public:
    Seguranca(int salario, std::string carga_horaria, bool horario_noturno);
    virtual ~Seguranca();
    virtual int calcular_salario(); // calcula o salario
    bool get_horario_noturno();     // retorna se o seguranca trabalha a noite ou nao
};
