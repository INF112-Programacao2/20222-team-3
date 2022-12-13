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

//exibe a tela inicial do sistema
void menu_inicial()
{
    std::cout << "\n ----------------------------" << std::endl;
    std::cout << "Selecione uma da opcoes abaixo: "<< std::endl;
    std::cout << "(1) Ver exposicoes" << std::endl;
    std::cout << "(2) Ver segurancas" << std::endl;
    std::cout << "(3) Ver guias" << std::endl;
    std::cout << "(4) Arquivar obra" << std::endl;
    std::cout << "(5) Atribuir funcionarios" << std::endl;
    std::cout << "(6) Ver financas" << std::endl;
    std::cout << "(7) Sair";
    std::cout << "\n ----------------------------\n";
}

//identifica qual a opcao escolhida pelo usuario
void funcoes_menu(Gerente &gerente)
{
    std::string escolha;
    while(true)
    {
        menu_inicial();
        std::cin >> escolha;

        if(escolha.size()>1 || escolha[0]<'1' || escolha[0]>'7'){ //se o valor inserido tiver uma posicao e estiver nesse intervalo
            std::cout << "Opcao invalida. Digite novamente" << std::endl; //pede paraa inserir novamente
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
            //percorre as exposicoes e exibe as obras associadas comos respectivos IDs
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
            int lucro=gerente.calcular_lucro();
            if(lucro>=0)
                std::cout<<"Lucro previsto: "<<lucro<<std::endl;
            else
                std::cout<<"Prejuizo previsto: "<<-1*lucro<<std::endl;
        }
        if(escolha=="7"){
            std::cout << "Obrigado por utilizar nosso sistema!" << std::endl;
            break;
        }
    }
}

int main(){
    Funcoes f; //cria o objeto usado para chamar as funcoes de verificacao
    std::ifstream fin("Dados.txt"); //abre o arquivo com as entradas do sistema
    if(!fin.is_open()){ //verifica se o arquivo foi aberto corretamente
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return 0;
    }
    std::string salario, numero_exposicoes, numero_segurancas, numero_guias;

    //verifica se os valores inseridos sao validos 
    std::getline(fin, salario);
    if(f.ler_int(salario)==-1 || f.ler_int(salario)==0){
        std::cout<<"Salario do gerente invalido.\n";
        return 0;
    }
    std::getline(fin, numero_exposicoes);
    if(f.ler_int(numero_exposicoes)==-1){
        std::cout<<"Numero de exposicoes invalido.\n";
        return 0;
    }
    std::getline(fin, numero_segurancas);
    if(f.ler_int(numero_segurancas)==-1){
        std::cout<<"Numero de segurancas invalido.\n";
        return 0;
    }
    std::getline(fin, numero_guias);
    if(f.ler_int(numero_guias)==-1){
        std::cout<<"Numero de guias invalido.\n";
        return 0;
    }
    Gerente *gerente; //cria um ponteiro do tipo gerente
    try{
        gerente=new Gerente(f.ler_int(salario), f.ler_int(numero_exposicoes), f.ler_int(numero_segurancas), f.ler_int(numero_guias), fin);
    }
    catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return 0;
    }
    funcoes_menu(*gerente); 
    fin.close(); //fecha o arquivo
    delete gerente; //deleta o gerente
    return 0;
}