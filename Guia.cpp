#include <iostream>
#include <string>
#include "Guia.h"

Guia::Guia(int salario,std::string carga_horaria,bool acessibilidade,int especialidade):
    Funcionario(salario,carga_horaria), _acessibilidade(acessibilidade), _especialidade(especialidade){}

Guia::~Guia(){};

int Guia::get_especialidade()
{
    return _especialidade;     // retorna o valor da especialidade
};
bool Guia::get_acessibilidade()
{
    return _acessibilidade; //retorna se true ou false para acessibilidade
};

int Guia::calcular_salario()
{
    // Quantidade de dias trabalhados (respresentado por '1')
    int cont=0;
    for(int i=0;i<get_carga_horaria().size();i++)
        if(get_carga_horaria()[i]=='1') //se a posicao da string e 1 ele trabalha naquele dia
            cont++; //incrementa contador
    return get_salario() * cont * 4 + (200 * _especialidade);
};
