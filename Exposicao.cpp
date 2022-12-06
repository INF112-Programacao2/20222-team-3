#include "Exposicao.h"

Exposicao::Exposicao(std::string nome,int numero_artistas,int semana,bool acessibilidade,int visitantes):
    Movimento(nome,numero_artistas),_semana(semana),_acessibilidade(acessibilidade),_visitantes(visitantes),_alocado(false){}
    
void Exposicao::aloca_vigilancia(){
    if(_alocado)
        return;
    _vigilancia=new int*[7];
    _vigilancia_noturna=new int*[7];
    for(int i=0;i<7;i++){
        _vigilancia[i]=new int[calcular_popularidade()+1];  //+1 pois a primeira posicao pertence ao guia
        _vigilancia_noturna[i]=new int[calcular_popularidade()/2];
    }
    _alocado=true;
}
void Exposicao::desaloca_vigilancia(){
    if(!_alocado)
        return;
    for(int i=0;i<7;i++){
        delete _vigilancia[i];
        delete _vigilancia_noturna[i];
    }
    delete _vigilancia;
    delete _vigilancia_noturna;
    _alocado=false;
}

Exposicao::~Exposicao(){
    if(_alocado)
        desaloca_vigilancia();
}

int** Exposicao::get_vigilancia(){
    return _vigilancia;
}  
int** Exposicao::get_vigilancia_noturna(){
    return _vigilancia_noturna;
}
int Exposicao::get_semana(){
    return _semana;
}
bool Exposicao::get_acessibilidade(){
    return _acessibilidade;
}
int Exposicao::get_visitantes(){
    return _visitantes;
}
bool Exposicao::get_alocado(){
    return _alocado;
}
void Exposicao::ver_vigilancia(){
    if(!_alocado)
        return;
    std::string dias[7]={"Domingo","Segunda","Terca","Quarta","Quinta","Sexta","Sabado"};
    for(int i=0;i<7;i++){
        std::cout<<dias[i]<<":"<<std::endl;
        for(int j=0;j<calcular_popularidade()+1;j++)
            std::cout<<_vigilancia[i][j]<<" ";
        std::cout<<std::endl;
    }
}
void Exposicao::ver_vigilancia_noturna(){
    if(!_alocado)
        return;
    std::string dias[7]={"Domingo","Segunda","Terca","Quarta","Quinta","Sexta","Sabado"};
    for(int i=0;i<7;i++){
        std::cout<<dias[i]<<":"<<std::endl;
        for(int j=0;j<calcular_popularidade()/2;j++)
            std::cout<<_vigilancia_noturna[i][j]<<" ";
        std::cout<<std::endl;
    }
}
float Exposicao::calcular_preco(){
    return 20*calcular_popularidade();
}