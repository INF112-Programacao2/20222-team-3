#include "Funcionario.h"
#include <exception>

Funcionario::Funcionario(int salario,std::string carga_horaria): 
   Pessoa(salario), _carga_horaria(carga_horaria){}

Funcionario::~Funcionario()
{};

std::string Funcionario::get_carga_horaria()
{
   return _carga_horaria;
}