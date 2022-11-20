#include "Gerente.h"

Gerente::Gerente(std::string entrada){} //em construcao
Gerente::~Gerente(){
    delete exposicoes;
    delete segurancas;
    delete guias;
}
int Gerente::get_numero_exposicoes(){
    return numero_exposicoes;
}
int Gerente::get_numero_segurancas(){
    return numero_segurancas;
}
int Gerente::get_numero_guias(){
    return numero_guias;
}
void Gerente::ver_exposicoes(){
    for(int i=0;i<get_numero_exposicoes();i++){
        std::cout<<"Semana "<<i+1<<": ";
        std::cout<<exposicoes[i].get_nome()<<std::endl;
    }
}
void Gerente::ver_segurancas(){
    for(int i=0;i<get_numero_segurancas();i++)
        std::cout<<segurancas[i].get_id()<<" ";
    std::cout<<std::endl;
}
void Gerente::ver_guias(){
    for(int i=0;i<get_numero_guias();i++)
        std::cout<<guias[i].get_id()<<" ";
    std::cout<<std::endl;
}
void Gerente::arquivar_obra(int id_obra){
    for(int i=0;i<get_numero_exposicoes();i++)
        for(int j=0;j<exposicoes[i].get_numero_artistas();j++)
            for(int k=0;k<artistas[j].get_numero_obras();k++)
                if(obras[k].get_id()==id_obra){
                    obras[k].arquivada=true;
                    return;
                }
}
void Gerente::atribuir_funcionarios(int id_exposicao){} //em construcao
float Gerente::calcular_lucro(){
    float receita=0,despesa=0;
    for(int i=0;i<get_numero_exposicoes();i++)
        receita+=exposicoes[i].get_preco()*exposicoes[i].get_visitantes();
    for(int i=0;i<get_numero_segurancas();i++)
        despesa+=segurancas[i].calcular_salario();
    for(int i=0;i<get_numero_guias();i++)
        despesa+=guias[i].calcular_salario();
    return receita-despesa;
}
float Gerente::calcular_salario(){
    return get_salario()*7*(28-4); //trabalha 7 horas por dia, nos 28 dias do mes menos os 4 domingos
}