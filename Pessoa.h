#pragma once
#include <iostream>

class Pessoa
{
private:
    static int _id_geral; // id geral das pessoas
    int _id;              // id da pessoa
    int _salario;         // salario da pessoa

public:
    Pessoa(int salario);
    virtual ~Pessoa();

    int get_salario();                  // retorna o salario
    int get_id();                       // retorna o id
    virtual int calcular_salario() = 0; // usado para calcular o salario, implementado nas classes derivadas
};