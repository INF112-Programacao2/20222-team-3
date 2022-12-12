#include "Exposicao.h"

Exposicao::Exposicao(std::string nome,int numero_artistas,int popularidade,int semana,bool acessibilidade,int visitantes):
    Movimento(nome,numero_artistas,popularidade),_semana(semana),_acessibilidade(acessibilidade),_visitantes(visitantes)
    {
        _vigilancia=new int*[7];
        _vigilancia_noturna=new int*[7];
        for(int i=0;i<7;i++){
            _vigilancia[i]=new int[popularidade+1];  //+1 pois a primeira posicao pertence ao guia
            _vigilancia_noturna[i]=new int[popularidade/2];
        }
    }
    
void Exposicao::desaloca_vigilancia(){
    for(int i=0;i<7;i++){
        delete _vigilancia[i];
        delete _vigilancia_noturna[i];
    }
    delete _vigilancia;
    delete _vigilancia_noturna;
}

Exposicao::~Exposicao(){
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
void Exposicao::ver_vigilancia(){
    std::string dias[7]={"Domingo","Segunda","Terca","Quarta","Quinta","Sexta","Sabado"};
    for(int i=0;i<7;i++){
        std::cout<<dias[i]<<":"<<std::endl;
        for(int j=0;j<get_popularidade()+1;j++)
            std::cout<<_vigilancia[i][j]<<" ";
        std::cout<<std::endl;
    }
}
void Exposicao::ver_vigilancia_noturna(){
    std::string dias[7]={"Domingo","Segunda","Terca","Quarta","Quinta","Sexta","Sabado"};
    for(int i=0;i<7;i++){
        std::cout<<dias[i]<<":"<<std::endl;
        for(int j=0;j<get_popularidade()/2;j++)
            std::cout<<_vigilancia_noturna[i][j]<<" ";
        std::cout<<std::endl;
    }
}
int Exposicao::calcular_preco(){
    return 12*get_popularidade();
}