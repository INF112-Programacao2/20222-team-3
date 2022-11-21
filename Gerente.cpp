#include "Gerente.h"

Gerente::Gerente(float salario,int numero_exposicoes,int numero_segurancas,int numero_guias):
    Pessoa(salario),_numero_exposicoes(numero_exposicoes),_numero_segurancas(numero_segurancas),_numero_guias(numero_guias),_carregado(false){}

Gerente::~Gerente(){
    if(_carregado)
        descarregar_sistema();
}

void Gerente::carregar_sistema(){
    _exposicoes=new *Exposicao[_numero_exposicoes];
    for(int i=0;i<_numero_exposicoes;i++){
        std::string nome;
        int numero_artistas;
        int semana=i+1;
        bool acessibilidade;
        int visitantes;
        std::cin>>nome>>numero_artistas>>acessibilidade>>visitantes;
        _exposicoes[i]=new Exposicao(nome,numero_artistas,semana,acessibilidade,visitantes);
        _exposicoes[i]->get_artistas()=new *Artista[numero_artistas];
        for(int j=0;j<numero_artistas;j++){
            int popularidade;
            int numero_obras;
            std::cin>>nome>>popularidade>>numero_obras;
            _exposicoes[i]->get_artistas()[j]=new Artista(nome,popularidade,numero_obras);
            _exposicoes[i]->get_artistas()[j]=new *Obra[numero_obras];
            for(int k=0;k<numero_obras;k++){
                std::cin>>nome;
                _exposicoes[i]->get_artistas()[j]->get_obras()[k]=new Obra(nome);
            }      
        }
    }
    //falta carregar os segurancas e guias no sistema
    _carregado=true;
}
void Gerente::descarregar_sistema(){
    for(int i=0;i<_numero_exposicoes;i++){
        for(int j=0;j<_exposicoes[i]->get_numero_artistas();j++)
            delete _exposicoes[i]->get_artistas()[j]->get_obras();
        delete exposicoes[i]->get_artistas();
    }
    delete _exposicoes;
    //falta descarregar os segurancas e guias no sistema 
    _carregado=false;        
}

Exposicao** Gerente::get_exposicoes(){
    return _exposicoes;
}
Seguranca** Gerente::get_segurancas(){
    return _segurancas;
}
Guia** Gerente::get_guias(){
    return _guias;
}
int Gerente::get_numero_exposicoes(){
    return _numero_exposicoes;
}
int Gerente::get_numero_segurancas(){
    return _numero_segurancas;
}
int Gerente::get_numero_guias(){
    return _numero_guias;
}
bool Gerente::get_carregado(){
    return _carregado;
}
void Gerente::ver_exposicoes(){
    for(int i=0;i<_numero_exposicoes;i++){
        std::cout<<"Semana "<<i+1<<": ";
        std::cout<<_exposicoes[i]->get_nome()<<std::endl;
    }
}
void Gerente::ver_segurancas(){
    for(int i=0;i<_numero_segurancas;i++)
        std::cout<<_segurancas[i]->get_ID()<<" ";
    std::cout<<std::endl;
}
void Gerente::ver_guias(){
    for(int i=0;i<_numero_guias;i++)
        std::cout<<_guias[i]->get_ID()<<" ";
    std::cout<<std::endl;
}
void Gerente::arquivar_obra(int ID_obra){
    for(int i=0;i<_numero_exposicoes;i++)
        for(int j=0;j<_exposicoes[i]->get_numero_artistas();j++)
            for(int k=0;k<_exposicoes[i]->get_artistas()[j]->get_numero_obras();k++)
                if(_exposicoes[i]->get_artistas()[j]->get_obras()[k]->get_ID()==ID_obra){
                    _obras[k].set_arquivada(true);
                    return;
                }
}

void Gerente::atribuir_funcionarios(int ID_exposicao){} //em construcao

float Gerente::calcular_lucro(){
    float receita=0,despesa=0;
    for(int i=0;i<_numero_exposicoes;i++)
        receita+=_exposicoes[i]->calcular_preco()*_exposicoes[i]->get_visitantes();
    for(int i=0;i<_numero_segurancas;i++)
        despesa+=_segurancas[i]->calcular_salario();
    for(int i=0;i<_numero_guias;i++)
        despesa+=_guias[i]->calcular_salario();
    return receita-despesa;
}
float Gerente::calcular_salario(){
    return get_salario()*7*(28-4); //trabalha 7 horas por dia, nos 28 dias do mes menos os 4 domingos
}