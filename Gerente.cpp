#include "Gerente.h"

Gerente::Gerente(float salario,int numero_exposicoes,int numero_segurancas,int numero_guias):
    Pessoa(salario),_numero_exposicoes(numero_exposicoes),_numero_segurancas(numero_segurancas),_numero_guias(numero_guias),_carregado(false){}

void Gerente::carregar_sistema(){
    float salario; 
    std::string carga_horaria; 
    _exposicoes=new Exposicao*[_numero_exposicoes];
    for(int i=0;i<_numero_exposicoes;i++){
        std::string nome;
        int numero_artistas;
        int semana=i+1;
        bool acessibilidade;
        int visitantes;
        std::cin>>nome>>numero_artistas>>acessibilidade>>visitantes;
        _exposicoes[i]=new Exposicao(nome,numero_artistas,semana,acessibilidade,visitantes);
        _exposicoes[i]->carregar_sistema();
    }
        _segurancas=new Seguranca*[_numero_segurancas];
        for(int j=0; j < _numero_segurancas;j++)
        {
            bool horario_noturno;
            std::cin>>salario>>carga_horaria>>horario_noturno;
            _segurancas[j]= new Seguranca(salario, carga_horaria, horario_noturno)
        }
        _guias=new Guia*[_numero_guias];
        for(int k = 0; k < _numero_guias; k++)
        {
            bool acessibilidade;
            int especialidade;
            std::cin >> salario >> carga_horaria >> acessibilidade >> especialidade;
            _guias[k]= new Guia(salario, carga_horaria, acessibilidade, especialidade);
        }
    
    _carregado=true;
}
void Gerente::descarregar_sistema(){
    if(!_carregado)
        return;
    for(int i=0;i<_numero_exposicoes;i++)
        _exposicoes[i]->descarregar_sistema();
    for(int j = 0; j < _numero_segurancas; j++)
    {
        delete _segurancas[j];
    }
    for(int k = 0; k < _numero_guias; k++)
    {
        delete _guias[k];
    }
    delete _segurancas;
    delete _guias;
    delete _exposicoes;
    _carregado=false;        
}
Gerente::~Gerente(){
    if(_carregado)
        descarregar_sistema();
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

void Gerente::atribuir_funcionarios(int ID_exposicao){
    Exposicao* exposicao;
    for(int i=0;i<_numero_exposicoes;i++)
        if(_exposicoes[i]->get_id()==ID_exposicao){
            exposicao=_exposicoes[i];
            break;
        }
        
    for(int i=0;i<7;i++){  //para cada dia da semana

        //escolha do guia
        Guia* guia;
        for(int j=0;j<_numero_guias;j++)
            if(exposicao->get_acessibilidade()==_guias[j]->get_acessibilidade() && exposicao->calcular_popularidade()==_guias[j]->get_especialidade()){
                guia=_guias[j];
                break;
            }
        exposicao->get_vigilancia()[i][0]=guia->get_id();  //primeira posicao guarda o guia

        //escolha dos segurancas
        Seguranca* seguranca;
        //horario diurno
        int vigilancia_necessaria=exposicao->calcular_popularidade();
        for(int j=0;j<_numero_segurancas;j++)
            if(_segurancas[j]->get_carga_horaria()[i]=='1'){  //se o seguranca trabalha no dia da semana i
                seguranca=_segurancas[j];  //escolhe seguranca
                exposicao->get_vigilancia()[i][vigilancia_necessaria]=seguranca->get_id();  //guarda seu id no vetor da exposicao
                vigilancia_necessaria--;  //menos um seguranca faltando
                if(vigilancia_necessaria<1) //se ficar menor que 1, exposicao ja tem segurancas suficientes
                    break;
            }
        //horario noturno
        vigilancia_necessaria=exposicao->calcular_popularidade()/2;
        for(int j=0;j<_numero_segurancas;j++)
            if(_segurancas[j]->get_carga_horaria()[i]=='1' && _segurancas[j]->get_horario_noturno()==true){ 
                seguranca=_segurancas[j]; 
                exposicao->get_vigilancia_noturna()[i][vigilancia_necessaria]=seguranca->get_id();  
                vigilancia_necessaria--; 
                if(vigilancia_necessaria<1) 
                    break;
            }

    }
}

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