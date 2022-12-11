#include <iostream>
#include <ifstream>
#include "Movimento.h"
#include "Gerente.h"
#include "Guia.h"
#include "Seguranca.h"
#include "Exposicao.h"
#include "Obra.h"
#include "Artista.h"

int ler_int(std::string str){
    int num=0;
    for(int i=0;i<str.size();i++){
        if(!isdigit(str[i]))
            return num;
        num*=10;
        num+=str[i]-'0';
    }
    return num;
}

int ler_digito(std::string str){
    if(str.size()!=1 || str[0]-'0' < 1 || str[0]-'0' > 5)
        return 0;
    return str[0]-'0';
}
int ler_bool(std::string str){
    if(str.size()!=1 || str[0]-'0' != 1 || str[0]-'0' != 0)
        return 2;
    return str[0]-'0';
}

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
    
        if(escolha="1"){
            gerente.ver_exposicoes();
        }
        if(escolha="2"){
            gerente.ver_segurancas();
        }
        if(escolha="3"){
            gerente.ver_guias();
        }
        if(escolha="4"){
            try{
                gerente.arquivar_obra();
            } 
            catch(std::invalid_argument &e){
                std::cout<<e.what()<<std::endl;
            }
        }
        if(escolha="5"){
            try{
            gerente.atribuir_funcionarios();
            } 
            catch(std::invalid_argument &e){
                std::cout<<e.what()<<std::endl;
            }
        }
        if(escolha=="6"){
            gerente.calcular_lucro();
        }
        if(escolha=="7"){
            break;
        }
    }
}

int main(){
    ifstream fin("Dados.txt");
    if(!fin.is_open()){
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return 0;
    }
    std::string salario, numero_exposicoes, numero_segurancas, numero_guias;
    std::getline(std::fin, salario);
    if(ler_int(salario)==0){
        std::cout<<"Salario do gerente invalido.\n";
        return 0;
    }
    std::getline(std::fin, numero_exposicoes);
    if(ler_int(numero_exposicoes)==0){
        std::cout<<"Numero de exposicoes invalido.\n";
        return 0;
    }
    std::getline(std::fin, numero_segurancas);
    if(ler_int(numero_segurancas)==0){
        std::cout<<"Numero de segurancas invalido.\n";
        return 0;
    }
    std::getline(std::fin, numero_guias);
    if(ler_int(numero_guias)==0){
        std::cout<<"Numero de guias invalido.\n";
        return 0;
    }
    try{
        Gerente gerente(ler_int(salario), ler_int(numero_exposicoes), ler_int(numero_segurancas), ler_int(numero_guias));
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    funcoes_menu(gerente);
    fin.close();
    return 0;
}