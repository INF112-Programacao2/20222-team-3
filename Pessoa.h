#pragma once
#include <iostream>

class Pessoa
{
private:
    // Dados Privados
    static int _id_geral;
    int _id;
    int _salario;

public:
    // Construtor
    Pessoa(int salario);
    // Destrutor
    virtual ~Pessoa();

    // Métodos Públicos
    int get_salario();
    int get_id();
    // Interface
    virtual int calcular_salario() = 0;
};