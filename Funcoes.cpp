#include"Funcoes.h"

int Funcoes::ler_int(std::string str){
    int num=0;
    for(int i=0;i<str.size();i++){
        if(!isdigit(str[i]))
            return num;
        num*=10;
        num+=str[i]-'0';
    }
    return num;
}

int Funcoes::ler_digito(std::string str){
    if(str.size()!=1 || str[0]-'0' < 1 || str[0]-'0' > 5)
        return 0;
    return str[0]-'0';
}

int Funcoes::ler_bool(std::string str){
    if(str.size()!=1 || (str[0]-'0' != 1 && str[0]-'0' != 0))
        return 2;
    return str[0]-'0';
}