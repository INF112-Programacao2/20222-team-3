#include "Gerente.h"
#include "Funcoes.h"

void Gerente::carregar_sistema(std::ifstream &fin){
    Funcoes f; //cria a variavel que sera usada na chamada das funcoess
    std::string salario; 
    std::string carga_horaria; 
    _exposicoes=new Exposicao*[_numero_exposicoes]; //aloca dinamicamente um vetor de exposicoes
    for(int i=0;i<_numero_exposicoes;i++){
        std::string nome;
        std::string numero_artistas;
        int semana=i+1;
        std::string popularidade;
        std::string acessibilidade;
        std::string visitantes;
        std::getline(fin, nome);

        //verifica se os valores inseridos sao validos
        fin>>numero_artistas;
        if(f.ler_int(numero_artistas)==-1){
            std::cout<<"Em "<<nome << std::endl;
            throw std::invalid_argument("Numero de artistas invalido.");
        }
        fin>>popularidade;
        if(f.ler_int(popularidade)==-1){
            std::cout<<"Em "<<nome << std::endl;
            throw std::invalid_argument("Popularidade invalida.");
        }
        fin >> acessibilidade;
        if(f.ler_bool(acessibilidade)==2){
            std::cout<<"Em "<<nome<< std::endl;
            throw std::invalid_argument("Acessibilidade  deve ser 0(falso) ou 1(verdadeiro).");
        }
        fin>>visitantes;
        if(f.ler_int(visitantes)==-1){
            std::cout<<"Em "<<nome << std::endl;
            throw std::invalid_argument("Numero de visitantes invalido.");
        }
        fin.ignore(); //necessario para a entrada de dados ocorrer corretamente
        //aloca um objeto Exposicao em cada posicao e chama a funcao carregar sistema para essa exposicao
        _exposicoes[i]=new Exposicao(nome,f.ler_int(numero_artistas),f.ler_int(popularidade),semana,f.ler_bool(acessibilidade),f.ler_int(visitantes));
        _exposicoes[i]->carregar_sistema(fin);
    }

    _segurancas=new Seguranca*[_numero_segurancas]; //aloca dinamicamnete um vetor de segurancas

    //verifica se os dados inseridos sao validos
    fin>>salario;
    if(f.ler_int(salario)==-1)
        throw std::invalid_argument("Salario invalido para segurancas.");
    for(int i=0; i<_numero_segurancas;i++)
    {
        std::string horario_noturno;
        fin>>carga_horaria;
        if(carga_horaria.size()!=7){
            std::cout<<"No "<<i+1<<"o seguranca"<<std::endl;
            throw std::invalid_argument("Carga horaria deve ter 7 numeros(0s ou 1s).");
        }
        for(int x=0;x<7;x++)
            if(carga_horaria[x]!='1'&&carga_horaria[x]!='0'){
                std::cout<<"No "<<i+1<<"o seguranca"<<std::endl;
                throw std::invalid_argument("Carga horaria deve conter somente 0s ou 1s.");
            }
        fin>>horario_noturno;
        if(f.ler_bool(horario_noturno)==2){
            std::cout<<"No "<<i+1<<"o seguranca"<<std::endl;
            throw std::invalid_argument("Horario noturno  deve ser 0(falso) ou 1(verdadeiro).");
        }
        //aloca uma objeto Seguranca em cada posicao do vetor
        _segurancas[i]= new Seguranca(f.ler_int(salario),carga_horaria,f.ler_bool(horario_noturno));
    }

    _guias=new Guia*[_numero_guias]; //aloca dinamicamente um vetor de guias
    //verifica se as informacoes inseridas sao validas
    fin >> salario;
    if(f.ler_int(salario)==-1)
        throw std::invalid_argument("Salario invalido para guias.");
    for(int i = 0; i < _numero_guias; i++)
    {
        std::string acessibilidade;
        std::string especialidade;
        fin >> carga_horaria;
        if(carga_horaria.size()!=7){
            std::cout<<"No "<<i+1<<"o guia"<<std::endl;
            throw std::invalid_argument("Carga horaria deve ter 7 numeros(0s ou 1s).");
        }
        for(int x=0;x<7;x++)
            if(carga_horaria[x]!='1'&&carga_horaria[x]!='0'){
                std::cout<<"No "<<i+1<<"o guia"<<std::endl;
                throw std::invalid_argument("Carga horaria deve conter somente 0s ou 1s.");
            }
        fin >> acessibilidade;
        if(f.ler_bool(acessibilidade)==2){
            std::cout<<"No "<<i+1<<"o guia"<<std::endl;
            throw std::invalid_argument("Acessibilidade deve ser 0(falso) ou 1(verdadeiro).");
        }
        fin>>especialidade;
        // especialidade recebe inteiros entre 1 e 5
        if(f.ler_digito(especialidade)==0){
            std::cout<<"No "<<i+1<<"o guia"<<std::endl;
            throw std::invalid_argument("Especialidade s?? permite inteiros entre 1 e 5.");
        }
        //aloca um objeto Guia em cada posicao do vetor
        _guias[i]= new Guia(f.ler_int(salario),carga_horaria,f.ler_bool(acessibilidade),f.ler_digito(especialidade));
    }
}

Gerente::Gerente(int salario,int numero_exposicoes,int numero_segurancas,int numero_guias, std::ifstream &fin):
    Pessoa(salario),_numero_exposicoes(numero_exposicoes),_numero_segurancas(numero_segurancas),_numero_guias(numero_guias)
    {
        carregar_sistema(fin);
    }

Gerente::~Gerente(){
    for(int i=0;i<_numero_exposicoes;i++)
        delete _exposicoes[i];
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
    //acessa cada exposicao e exibe os artistas e obras presentes nela
    for(int i=0;i<_numero_exposicoes;i++){
        std::cout<<"Semana "<<i+1<<": ";
        std::cout<<_exposicoes[i]->get_nome()<<std::endl;
        for(int j=0;j<_exposicoes[i]->get_numero_artistas();j++){
            std::cout<<"Artista: "<<_exposicoes[i]->get_artistas()[j]->get_nome()<<std::endl;
            for(int k=0;k<_exposicoes[i]->get_artistas()[j]->get_numero_obras();k++)
                if(!(_exposicoes[i]->get_artistas()[j]->get_obras()[k]->get_arquivada())) //se a obra nao esta arquivada
                    std::cout<<_exposicoes[i]->get_artistas()[j]->get_obras()[k]->get_nome() << std::endl; 
        }
        std::cout << std::endl; 
    }
}
void Gerente::ver_segurancas(){
    //percorre o vetor de segurancas e exibe os IDs
    for(int i=0;i<_numero_segurancas;i++)
        std::cout<<_segurancas[i]->get_id()<<" ";
    std::cout<<std::endl;
}
void Gerente::ver_guias(){
    //percorre o vetor de guias e exibe os IDs
    for(int i=0;i<_numero_guias;i++)
        std::cout<<_guias[i]->get_id()<<" ";
    std::cout<<std::endl;
}
void Gerente::arquivar_obra(int ID_obra){
    //percorre o vetor de exposicoes, artista e obras ate achar a obra do ID correspondente
    for(int i=0;i<_numero_exposicoes;i++)
        for(int j=0;j<_exposicoes[i]->get_numero_artistas();j++)
            for(int k=0;k<_exposicoes[i]->get_artistas()[j]->get_numero_obras();k++)
                if(_exposicoes[i]->get_artistas()[j]->get_obras()[k]->get_id()==ID_obra){
                    _exposicoes[i]->get_artistas()[j]->get_obras()[k]->set_arquivada(true); //arquiva a obra
                    return;
                }
    throw std::invalid_argument("ID inserido nao foi cadastrado!");
}

void Gerente::atribuir_funcionarios(){
    for(int l=0;l<_numero_exposicoes;l++){
        for(int i=0;i<7;i++){  //para cada dia da semana
            //escolha do guia
            Guia* guia;
            for(int j=0;j<_numero_guias;j++){
                if(_exposicoes[l]->get_popularidade()==_guias[j]->get_especialidade()){
                    if(_exposicoes[l]->get_acessibilidade() && !(_guias[j]->get_acessibilidade()))
                        continue;
                    guia=_guias[j];
                    break;
                }
                if(j==_numero_guias-1){
                    std::string dias[7]={"domingo","segunda","terca","quarta","quinta","sexta","sabado"};
                    std::cout<<"Em "<<_exposicoes[l]->get_nome() <<" em "<< dias[i]<< std::endl;
                    throw std::invalid_argument("Nao ha guias adequados suficientes!");
                }
            }
            _exposicoes[l]->get_vigilancia()[i][0]=guia->get_id();  //primeira posicao guarda o guia

            //escolha dos segurancas
            Seguranca* seguranca;
            //horario diurno
            int vigilancia_necessaria=_exposicoes[l]->get_popularidade();
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
                    std::cout<<"Em "<<_exposicoes[l]->get_nome() <<" em "<< dias[i]<< std::endl;
                    throw std::invalid_argument("Nao ha segurancas adequados suficientes!");
                }
            }
            //horario noturno
            vigilancia_necessaria=_exposicoes[l]->get_popularidade()/2;
            for(int j=0;j<_numero_segurancas;j++){
                if(_segurancas[j]->get_carga_horaria()[i]=='1' && _segurancas[j]->get_horario_noturno()==true){ 
                    seguranca=_segurancas[j]; 
                    _exposicoes[l]->get_vigilancia_noturna()[i][vigilancia_necessaria-1]=seguranca->get_id();  
                    vigilancia_necessaria--; 
                    if(vigilancia_necessaria<1) 
                        break;
                }
                if(j==_numero_segurancas-1){
                    std::string dias[7]={"domingo","segunda","terca","quarta","quinta","sexta","sabado"};
                    std::cout<<"Em "<<_exposicoes[l]->get_nome() <<" em "<< dias[i]<< std::endl;
                    throw std::invalid_argument("Nao ha segurancas adequados suficientes a noite!");
                }
            }
        }
        std::cout<<std::endl<<_exposicoes[l]->get_nome()<<std::endl<<std::endl;
        _exposicoes[l]->ver_vigilancia();
        std::cout<<"NOTURNO\n";
        _exposicoes[l]->ver_vigilancia_noturna();
    }
}

int Gerente::calcular_salario(){
    return get_salario()*(28-4); //trabalha 7 horas por dia, nos 28 dias do mes menos os 4 domingos
}

int Gerente::calcular_lucro(){
    int receita=0,despesa=0;
    //calcula e exibe o lucro com visitantes de cada exposicao
    for(int i=0;i<_numero_exposicoes;i++){
        int receita_exposicao=_exposicoes[i]->calcular_preco()*_exposicoes[i]->get_visitantes();
        receita+=receita_exposicao;
        std::cout<<"Receita da exposicao '"<<_exposicoes[i]->get_nome()<<"' foi: "<<receita_exposicao<<std::endl;
    }
    //calcula o salario de cada seguranca e acumula nas despesas
    for(int i=0;i<_numero_segurancas;i++){
        int despesa_seguranca=_segurancas[i]->calcular_salario();
        despesa+=despesa_seguranca;
        std::cout<<"Despesa com seguranca "<<_segurancas[i]->get_id()<<" foi: "<<despesa_seguranca<<std::endl; //exibe o salario
    }
    //calcula e exibe o salario de cada guia e nas despesas
    for(int i=0;i<_numero_guias;i++){
        int despesa_guia=_guias[i]->calcular_salario();
        despesa+=despesa_guia;
        std::cout<<"Despesa com guia "<<_guias[i]->get_id()<<" foi: "<<despesa_guia<<std::endl; //exibe o salario
    }
    despesa+=calcular_salario(); //calcula o salario do gerente e acumula nas despesas
    std::cout<<"Despesa com o gerente foi: "<<calcular_salario()<<std::endl; //exibe o salario
    return receita-despesa;
}
