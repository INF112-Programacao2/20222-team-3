#include"Funcoes.h"

int Funcoes::ler_int(std::string str){
    if(str=="")
        return -1;
    int num=0;
    for(int i=0;i<str.size();i++){ //percorre cada posicao da string
        if(!isdigit(str[i])) //se a posicao nao e um digito
            return -1; //retorna -1
        num*=10; //multiplica o numero por 10 caso seja um numero com mais de um algarismo
        num+=str[i]-'0'; //converte para inteiro
    }
    return num;
}

int Funcoes::ler_digito(std::string str){
    if(str.size()!=1 || str[0]-'0' < 1 || str[0]-'0' > 5) //vefica se so existe uma posicao e se esta no intervalo
        return 0;
    return str[0]-'0'; //converte para inteiro
}

int Funcoes::ler_bool(std::string str){
    if(str.size()!=1 || (str[0]-'0' != 1 && str[0]-'0' != 0)) //verifica se so existe uma posicao e se e 0 ou 1
        return 2;
    return str[0]-'0'; //converte para inteiro
}