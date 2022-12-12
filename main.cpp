#include <iostream>
#include <fstream>
#include "Movimento.h"
#include "Gerente.h"
#include "Guia.h"
#include "Seguranca.h"
#include "Exposicao.h"
#include "Obra.h"
#include "Artista.h"
#include "Funcoes.h"

void menu_inicial()
{
    std::cout << "Selecione uma da opcoes abaixo: "<< std::endl;
    std::cout << "(1) Ver exposicoes" << std::endl;
    std::cout << "(2) Ver segurancas" << std::endl;
    std::cout << "(3) Ver guias" << std::endl;
    std::cout << "(4) Arquivar obra" << std::endl;
    std::cout << "(5) Atribuir funcionarios" << std::endl;
    std::cout << "(6) Calcular lucro" << std::endl;
    std::cout << "(7) Sair" << std::endl;
}

void funcoes_menu(Gerente &gerente)
{
    std::string escolha;
    while(true)
    {
        menu_inicial();
        std::cin >> escolha;

        if(escolha.size()>1 || escolha[0]<'1' || escolha[0]>'7'){
            std::cout << "Opcao invalida. Digite novamente" << std::endl;
            continue;
        }
    
        if(escolha=="1"){
            gerente.ver_exposicoes();
        }
        if(escolha=="2"){
            gerente.ver_segurancas();
        }
        if(escolha=="3"){
            gerente.ver_guias();
        }
        if(escolha=="4"){
            for(int i=0;i<gerente.get_numero_exposicoes();i++)
                for(int j=0;j<gerente.get_exposicoes()[i]->get_numero_artistas();j++)
                    gerente.get_exposicoes()[i]->get_artistas()[j]->ver_obras();
            int id;
            std::cout<<"Insira o ID:\n";
            std::cin>>id;
            try{
                gerente.arquivar_obra(id);
            } 
            catch(std::invalid_argument &e){
                std::cout<<e.what()<<std::endl;
            }
        }
        if(escolha=="5"){
            try{
            gerente.atribuir_funcionarios();
            } 
            catch(std::invalid_argument &e){
                std::cout<<e.what()<<std::endl;
            }
        }
        if(escolha=="6"){
            std::cout<<"RS "<<gerente.calcular_lucro()<<std::endl;
        }
        if(escolha=="7"){
            break;
        }
    }
}

int main(){
    Funcoes f;
    std::ifstream fin("Dados.txt");
    if(!fin.is_open()){
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return 0;
    }
    std::string salario, numero_exposicoes, numero_segurancas, numero_guias;
    std::getline(fin, salario);
    if(f.ler_int(salario)==0){
        std::cout<<"Salario do gerente invalido.\n";
        return 0;
    }
    std::getline(fin, numero_exposicoes);
    if(f.ler_int(numero_exposicoes)==0){
        std::cout<<"Numero de exposicoes invalido.\n";
        return 0;
    }
    std::getline(fin, numero_segurancas);
    if(f.ler_int(numero_segurancas)==0){
        std::cout<<"Numero de segurancas invalido.\n";
        return 0;
    }
    std::getline(fin, numero_guias);
    if(f.ler_int(numero_guias)==0){
        std::cout<<"Numero de guias invalido.\n";
        return 0;
    }
    Gerente *gerente;
    try{
        gerente=new Gerente(f.ler_int(salario), f.ler_int(numero_exposicoes), f.ler_int(numero_segurancas), f.ler_int(numero_guias), fin);
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return 0;
    }
    funcoes_menu(*gerente);
    fin.close();
    delete gerente;
    return 0;
}