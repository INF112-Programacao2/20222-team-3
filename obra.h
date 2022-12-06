#pragma once
#include <iostream>

class Obra {
    private:
        static int _id_geral;
        int _id;
        bool _arquivada;
        std::string _nome;
    public:
        Obra(std::string nome);
        ~Obra();
        int get_id();
        bool get_arquivada();
        std::string get_nome();
        void set_arquivada(bool arquivada);

};