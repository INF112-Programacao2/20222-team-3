#include "Exposicao.h"

Exposicao::Exposicao(std::string nome,int numero_artistas,int popularidade,int semana,bool acessibilidade,int visitantes):
    Movimento(nome,numero_artistas,popularidade),_semana(semana),_acessibilidade(acessibilidade),_visitantes(visitantes)
    {
        //cria um vetor referente a cada dia da semana
        _vigilancia=new int*[7];
        _vigilancia_noturna=new int*[7];
        for(int i=0;i<7;i++){
            //aloca em cada dia da semana um vetor com o numero de funcionarios necessarios
            _vigilancia[i]=new int[popularidade+1];  //+1 pois a primeira posicao pertence ao guia
            _vigilancia_noturna[i]=new int[popularidade/2];//precisa de metade dos segurancas do que o dia
        }
    }

Exposicao::~Exposicao(){
    for(int i=0;i<7;i++){
        delete _vigilancia[i];
        delete _vigilancia_noturna[i];
    }
    delete _vigilancia;
    delete _vigilancia_noturna;
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
    //percorre a matriz de vigilancia exibindo os funcionarios alocados em cada dia
    std::string dias[7]={"Domingo","Segunda","Terca","Quarta","Quinta","Sexta","Sabado"};
    for(int i=0;i<7;i++){
        std::cout<<dias[i]<<":"<<std::endl;
        for(int j=0;j<get_popularidade()+1;j++)
            std::cout<<_vigilancia[i][j]<<" ";
        std::cout<<std::endl;
    }
}
void Exposicao::ver_vigilancia_noturna(){
    //percorre a matriz de vigilancia exibindo os funcionarios alocados em cada dia
    std::string dias[7]={"Domingo","Segunda","Terca","Quarta","Quinta","Sexta","Sabado"};
    for(int i=0;i<7;i++){
        std::cout<<dias[i]<<":"<<std::endl;
        for(int j=0;j<get_popularidade()/2;j++)
            std::cout<<_vigilancia_noturna[i][j]<<" ";
        std::cout<<std::endl;
    }
}
int Exposicao::calcular_preco(){
    return 12*get_popularidade(); //multiplica o valor base do ingresso pela popularidade da exposicao
}