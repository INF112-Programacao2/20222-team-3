#include "Exposicao.h"

Exposicao::Exposicao(int semana,bool acessibilidade,float preco,int visitantes,int id_guia)
{
    _semana=semana;
    _acessibilidade=acessibilidade;
    _preco=preco;
    _visitantes=visitantes;
    _id_guia=id_guia;
    vigilancia=new int*[7];
    vigilancia_noturna=new int*[7];
    for(int i=0;i<7;i++){
        vigilancia[i]=new int[calcular_popularidade()];
        vigilancia_noturna[i]=new int[calcular_popularidade()/2];
    }
}
Exposicao::~Exposicao(){
    for(int i=0;i<7;i++){
        delete vigilancia[i];
        delete vigilancia_noturna[i];
    }
    delete vigilancia;
    delete vigilancia_noturna;
}
int Exposicao::get_semana(){
    return _semana;
}
bool Exposicao::get_acessibilidade(){
    return _acessibilidade;
}
float Exposicao::get_preco(){
    return _preco;
}
int Exposicao::get_visitantes(){
    return _visitantes;
}
void Exposicao::ver_vigilancia(){
    dias[7]={"Domingo","Segunda","Terca","Quarta","Quinta","Sexta","Sabado"};
    for(int i=0;i<7;i++){
        std::cout<<dias[i]<<":"<<std::endl;
        for(int j=0;j<calcular_popularidade();j++)
            std::cout<<vigilancia[i][j]<<" ";
        std::cout<<std::endl;
    }
}
void Exposicao::ver_vigilancia_noturna(){
    dias[7]={"Domingo","Segunda","Terca","Quarta","Quinta","Sexta","Sabado"};
    for(int i=0;i<7;i++){
        std::cout<<dias[i]<<":"<<std::endl;
        for(int j=0;j<calcular_popularidade()/2;j++)
            std::cout<<vigilancia_noturna[i][j]<<" ";
        std::cout<<std::endl;
    }
}
int Exposicao::get_id_guia(){
    return _id_guia;
}