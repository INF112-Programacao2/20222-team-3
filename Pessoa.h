#pragma once
#include <iostream>

class Pessoa
{
private:
    static int _id_geral;
    int _id;
    float _salario;

public:
    Pessoa(int id, float salario);
    ~Pessoa();

    float get_salario_pessoa();
    int get_id();
    virtual float calcular_salario() = 0;
};