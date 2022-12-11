#include "Funcionario.h"
#include <exception>
Funcionario::Funcionario(std::string carga_horaria, int salario) : Pessoa(salario) // Construtor de pessoa
{

   _carga_horaria = carga_horaria;
   // Tratando exceção caso exista algum caracterer diferente de 1 e 0(que representa se ele foi ou não no dia)
   for (int i = 0; i < _carga_horaria.size(); i++)
      if (_carga_horaria[i] != '1' || _carga_horaria[i] == '0')
      {
         throw std::invalid_argument("Carga horaria só permite 0 e 1");
      }
   // Como isso vale por semana, o máximo de  caracteres é 7, tratando exceção
   if (_carga_horaria.size() != 7)
      throw std::invalid_argument("Insira somente 7 caracteres.");
}

Funcionario::~Funcionario(){

};

std::string Funcionario::get_carga_horaria()
{
   // retorna a string de carga horaria
   return _carga_horaria;
}