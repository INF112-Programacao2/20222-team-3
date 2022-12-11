#pragma once
#include <iostream>

class Pessoa
{
private:
    static int _id_geral;
    int _id;
    float _salario;

public:
    Pessoa(float salario);
    virtual ~Pessoa();

    float get_salario();
    int get_id();
    virtual float calcular_salario() = 0;
};