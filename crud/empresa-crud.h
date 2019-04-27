#ifndef EMPRESA_CRUD_H
#define EMPRESA_CRUD_H

#include <iostream>
#include "../modelos/empresa/empresa.h"
using namespace std;
Empresa criarEmpresa();
void adicionarFuncionario(list<Empresa> &empresa, Funcionario funcionario);
void listarFuncionarios(list<Empresa> empresas);
void aplicarAumento(list<Empresa> &empresas);
void listarMediaFuncionarios(list<Empresa> empresas);

#endif
