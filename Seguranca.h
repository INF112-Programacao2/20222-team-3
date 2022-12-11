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
    Seguranca(int salario,std::string carga_horaria,bool horario_noturno);
    // Destrutor
    virtual ~Seguranca();
    // Métodos
    virtual int calcular_salario();
    bool get_horario_noturno();
};
