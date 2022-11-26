#pragma once
#include <bits/stdc++.h>
#include "Funcionario.h"

class Seguranca : public  Funcionario
{
private:
    bool horario_noturno;

public:
    // Construtor
    Seguranca();
    // Destrutor
    ~Seguranca();
    // Métodos
    virtual float calcular_salario() override;
    bool get_horario_noturno();
};
