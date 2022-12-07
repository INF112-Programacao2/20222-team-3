#include "Funcionario.h"

Funcionario::Funcionario()
{

   carga_horaria = new bool[7];
   for (int i = 0; i < 7; ++i)
   {
      std::cin >> carga_horaria[i];
   }
}

Funcionario::~Funcionario()
{
   delete[] carga_horaria;
};

void Funcionario::get_carga_horaria()
{
   for (int i = 0; i < 7; ++i)
   {
      std::cout << carga_horaria[i] << " ";
   }
   std::cout << std::endl;
}