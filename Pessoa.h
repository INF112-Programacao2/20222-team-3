#pragma once
#include <bits/stdc++.h>

class Pessoa
{
private:
    int Id_Pessoa;
    float salario;

public:
    Pessoa();
    ~Pessoa();

    void get_salario_pessoa();
    void get_Id_pessoa();
    virtual float calcular_salario() = 0;
};