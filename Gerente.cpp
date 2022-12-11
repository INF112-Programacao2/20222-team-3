#include "Gerente.h"

void Gerente::carregar_sistema(){
    std::string salario; 
    std::string carga_horaria; 
    _exposicoes=new Exposicao*[_numero_exposicoes];
    for(int i=0;i<_numero_exposicoes;i++){
        std::string nome;
        std::string numero_artistas;
        int semana=i+1;
        std::string acessibilidade;
        std::string visitantes;
        std::getline(std::cin, nome);
        std::cin>>numero_artistas;
        if(ler_int(numero_artistas)==0)
            throw std::exception("Numero de artistas de "+nome+" invalido.");
        std::cin >> acessibilidade;
        if(ler_bool(acessibilidade)==2)
            throw std::exception("Acessibilidade de "+nome+" deve ser 0(falso) ou 1(verdadeiro).");
        std::cin>>visitantes;
        if(ler_int(visitantes)==0)
            throw std::exception("Numero de visitantes de "+nome+" invalido.");
        
        _exposicoes[i]=new Exposicao(nome,ler_int(numero_artistas),semana,ler_bool(acessibilidade),ler_int(visitantes));
        _exposicoes[i]->carregar_sistema();
    }

    _segurancas=new Seguranca*[_numero_segurancas];
    for(int i=0; i<_numero_segurancas;i++)
    {
        std::string horario_noturno;
        std::cin>>salario;
        if(ler_int(salario)==0)
            throw std::exception("Salario de "+to_string(_segurancas[i]->get_id())+" invalido.");
        std::cin>>carga_horaria;
        if(carga_horaria.size()!=7)
            throw std::exception("Carga horaria de "+to_string(_segurancas[i]->get_id())+" deve ter 7 numeros(0s ou 1s).");
        for(int x=0;x<7;x++)
            if(ler_bool(carga_horaria[x])==2)
                throw std::exception("Carga horaria de "+to_string(_segurancas[i]->get_id())+" deve conter somente 0s ou 1s.");
        std::cin>>horario_noturno;
        if(ler_bool(horario_noturno)==2)
            throw std::exception("Horario noturno de "+to_string(_segurancas[i]->get_id())+" deve ser 0(falso) ou 1(verdadeiro).");
        _segurancas[i]= new Seguranca(ler_int(salario),carga_horaria,ler_bool(horario_noturno));
    }

    _guias=new Guia*[_numero_guias];
    for(int i = 0; i < _numero_guias; i++)
    {
        std::string acessibilidade;
        std::string especialidade;
        std::cin >> salario;
        if(ler_int(salario)==0)
            throw std::exception("Salario de "+to_string(_guias[i]->get_id())+" invalido.");
        std::cin >> carga_horaria;
        if(carga_horaria.size()!=7)
            throw std::exception("Carga horaria de "+to_string(_guias[i]->get_id())+" deve ter 7 numeros(0s ou 1s).");
        for(int x=0;x<7;x++)
            if(ler_bool(carga_horaria[x])==2)
                throw std::exception("Carga horaria de "+to_string(_guias[i]->get_id())+" deve conter somente 0s ou 1s.");
        std::cin >> acessibilidade;
        if(ler_bool(acessibilidade)==2)
            throw std::exception("Acessibilidade de "+to_string(_guias[i]->get_id())+" deve ser 0(falso) ou 1(verdadeiro).");
        std::cin>>especialidade;
        // especialidade recebe inteiros entre 1 e 5
        if(ler_digito(especialidade)==0)
            throw std::exception("Especialidade só permite inteiros entre 1 e 5.");
        _guias[i]= new Guia(ler_int(salario),carga_horaria,ler_bool(acessibilidade),ler_digito(especialidade));
    }
}

Gerente::Gerente(int salario,int numero_exposicoes,int numero_segurancas,int numero_guias):
    Pessoa(salario),_numero_exposicoes(numero_exposicoes),_numero_segurancas(numero_segurancas),_numero_guias(numero_guias)
    {
        carregar_sistema();
    }

void Gerente::descarregar_sistema(){
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
}

Gerente::~Gerente(){
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
void Gerente::ver_exposicoes(){
    for(int i=0;i<_numero_exposicoes;i++){
        std::cout<<"Semana "<<i+1<<": ";
        std::cout<<_exposicoes[i]->get_nome()<<std::endl;
    }
}
void Gerente::ver_segurancas(){
    for(int i=0;i<_numero_segurancas;i++)
        std::cout<<_segurancas[i]->get_id()<<" ";
    std::cout<<std::endl;
}
void Gerente::ver_guias(){
    for(int i=0;i<_numero_guias;i++)
        std::cout<<_guias[i]->get_id()<<" ";
    std::cout<<std::endl;
}
void Gerente::arquivar_obra(int ID_obra){
    for(int i=0;i<_numero_exposicoes;i++)
        for(int j=0;j<_exposicoes[i]->get_numero_artistas();j++)
            for(int k=0;k<_exposicoes[i]->get_artistas()[j]->get_numero_obras();k++)
                if(_exposicoes[i]->get_artistas()[j]->get_obras()[k]->get_id()==ID_obra){
                    _obras[k].set_arquivada(true);
                    return;
                }
    throw std::exception("ID inserido nao foi cadastrado!");
}

void Gerente::atribuir_funcionarios(){
    for(int l=0;l<_numero_exposicoes;l++){
        for(int i=0;i<7;i++){  //para cada dia da semana
            //escolha do guia
            Guia* guia;
            for(int j=0;j<_numero_guias;j++){
                if(_exposicoes[l]->calcular_popularidade()==_guias[j]->get_especialidade()){
                    if(_exposicoes[l]->get_acessibilidade() && !(_guias[j]->get_acessibilidade()))
                        continue;
                    guia=_guias[j];
                    break;
                }
                if(j==_numero_guias-1){
                    std::string dias[7]={"domingo","segunda","terca","quarta","quinta","sexta","sabado"};
                    throw std::exception("Nao ha guias adequados suficientes para "+_exposicoes[l]->get_nome()+" em "+dias[i]+"!");
                }
            }
            _exposicoes[l]->get_vigilancia()[i][0]=guia->get_id();  //primeira posicao guarda o guia

            //escolha dos segurancas
            Seguranca* seguranca;
            //horario diurno
            int vigilancia_necessaria=_exposicoes[l]->calcular_popularidade();
            for(int j=0;j<_numero_segurancas;j++){
                if(_segurancas[j]->get_carga_horaria()[i]=='1'){  //se o seguranca trabalha no dia da semana i
                    seguranca=_segurancas[j];  //escolhe seguranca
                    _exposicoes[l]->get_vigilancia()[i][vigilancia_necessaria]=seguranca->get_id();  //guarda seu id no vetor da _exposicoes[l]
                    vigilancia_necessaria--;  //menos um seguranca faltando
                    if(vigilancia_necessaria<1) //se ficar menor que 1, exposicao ja tem segurancas suficientes
                        break;
                }
                if(j==_numero_segurancas-1){
                    std::string dias[7]={"domingo","segunda","terca","quarta","quinta","sexta","sabado"};
                    throw std::exception("Nao ha segurancas adequados suficientes para "+_exposicoes[l]->get_nome()+" em "+dias[i]+"!");
                }
            }
            //horario noturno
            vigilancia_necessaria=_exposicoes[l]->calcular_popularidade()/2;
            for(int j=0;j<_numero_segurancas;j++){
                if(_segurancas[j]->get_carga_horaria()[i]=='1' && _segurancas[j]->get_horario_noturno()==true){ 
                    seguranca=_segurancas[j]; 
                    _exposicoes[l]->get_vigilancia_noturna()[i][vigilancia_necessaria]=seguranca->get_id();  
                    vigilancia_necessaria--; 
                    if(vigilancia_necessaria<1) 
                        break;
                }
                if(j==_numero_segurancas-1){
                    std::string dias[7]={"domingo","segunda","terca","quarta","quinta","sexta","sabado"};
                    throw std::exception("Nao ha segurancas adequados suficientes para "+_exposicoes[l]->get_nome()+" em "+dias[i]+" a noite!");
                }
            }
        }
    }
}

int Gerente::calcular_lucro(){
    int receita=0,despesa=0;
    for(int i=0;i<_numero_exposicoes;i++)
        receita+=_exposicoes[i]->calcular_preco()*_exposicoes[i]->get_visitantes();
    for(int i=0;i<_numero_segurancas;i++)
        despesa+=_segurancas[i]->calcular_salario();
    for(int i=0;i<_numero_guias;i++)
        despesa+=_guias[i]->calcular_salario();
    return receita-despesa;
}
int Gerente::calcular_salario(){
    return get_salario()*7*(28-4); //trabalha 7 horas por dia, nos 28 dias do mes menos os 4 domingos
}