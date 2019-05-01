#include "funcionario.h"
Funcionario::Funcionario(string nome, double salario, string dataAdmissao){
    this->nome = nome;
    this->salario = salario;
    this->dataAdmissao = dataAdmissao;
}

Funcionario& Funcionario::operator= (Funcionario const &f){
    this->nome =f.nome;
    this->salario = f.salario;
    this->dataAdmissao = f.dataAdmissao;
    return *this;
}

ostream& operator<< (ostream &o, Funcionario const f) {
o << "nome: " << f.nome << " | salario : " << f.salario << " | contratado em: "<< f.dataAdmissao << " por " << f.nomeEmpresa << endl;
return o;
}

Funcionario::~Funcionario(){};
