#include <iostream>
#include <string>
#include "Guia.h"

Guia::Guia()
{
    std::string a, b;
    std::cin >> a >> b;
    funcao = a;
    especialidade = b;
};

Guia::~Guia(){};

void Guia::get_especialidade()
{

    std::cout << especialidade << std::endl;
};
void Guia::get_funcao()
{
    std::cout << funcao << std::endl;
};

float Guia::calcular_salario()
{
    float a;
    std::cin >> a;
    return a;
};
