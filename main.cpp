#include "Movimento.h"
#include "Gerente.h"
#include "Guia.h"
#include "Seguranca.h"
#include "Exposicao.h"
#include "Obra.h"
#include "Artista.h"

void menu_inicial()
{
    std::cout << "Bem Vindo" << std::endl;
    std::cout << "Selecione uma da opcoes abaixo: ";
    std::cout << "(1) Ver exposicoes" << std::endl;
    std::cout << "(2) Ver segurancas" << std::endl;
    std::cout << "(3) Ver guias" << std::endl;
    std::cout << "(4) Arquivar obra" << std::endl;
    std::cout << "(5) Atribuir funcionario" << std::endl;
    std::cout << "(6) Calcular lucro" << std::endl;
}

void funcoes_menu(std::string _escolha)
{
    if(escolha="1")
    {
        gerente.ver_exposicoes();
    }
        if(escolha="2")
    {
        gerente.ver_segurancas();
    }
        if(escolha="3")
    {
        gerente.ver_guias();
    }
        if(escolha="4")
    {
        gerente.arquivar_obra();
    }
        if(escolha="5")
    {
        gerente.atribuir_funcionarios();
    }
        if(escolha="6")
    {
        gerente.calcular_lucro();
    }
}

int main(){
    std::string escolha;
    bool validacao=true;
    Gerente gerente(125);
    gerente.carregar_sistema();
    menu_inicial();

    while(validacao)
    {
        std::cin >> escolha;

        if(escolha.size()>1 || escolha[0]<'1' || escolha[0]>'6')
            std::cout << "Insira uma das opcoes acima" << std::endl;
        else
            validacao=false;
    }
    funcoes_menu(escolha);

}