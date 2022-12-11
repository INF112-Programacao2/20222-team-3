#pragma once
#include <string>
#include "Funcionario.h"

class Seguranca : public Funcionario
{
private:
//métodos privados
    bool _horario_noturno;

public:
    // Construtor
    Seguranca(bool horario_noturno,std::string carga_horaria,int salario);
    // Destrutor
    virtual ~Seguranca();
    // Métodos
    virtual int calcular_salario();
    bool get_horario_noturno();
};
