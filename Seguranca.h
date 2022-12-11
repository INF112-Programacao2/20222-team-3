#pragma once
#include <bits/stdc++.h>
#include "Funcionario.h"

class Seguranca : public Funcionario
{
private:
    bool _horario_noturno;

public:
    // Construtor
    Seguranca(bool horario_noturno,std::string carga_horaria,float salario);
    // Destrutor
    virtual ~Seguranca();
    // Métodos
    virtual float calcular_salario();
    bool get_horario_noturno();
};
