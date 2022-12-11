#pragma once
#include <iostream>

class Pessoa
{
private:
    // Dados Privados
    static int _id_geral;
    int _id;
    float _salario;

public:
    // Construtor
    Pessoa(float salario);
    // Destrutor
    virtual ~Pessoa();

    // Métodos Públicos
    float get_salario();
    int get_id();
    // Interface
    virtual float calcular_salario() = 0;
};