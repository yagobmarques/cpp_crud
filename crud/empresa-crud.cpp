#include "empresa-crud.h"

Empresa criarEmpresa(){
    string nome, cnpj;
    cout << "Criar Empresa:\n Nome:" << endl;
    cin >> nome;
    cout << "CNPJ:" << endl;
    cin >> cnpj;
    Empresa empresa = Empresa(nome, cnpj);
    return empresa;
}

void adicionarFuncionario(vector<Empresa> &empresas, Funcionario funcionario){   
    Empresa empresaEscolhida = escolherEmpresa(empresas);
    empresaEscolhida.inserirFuncionario(funcionario);
    for (vector<Empresa>::iterator i=empresas.begin(); i!= empresas.end(); ++i ){
        if(i->getCnpj() == empresaEscolhida.getCnpj()){
            empresas.erase(i);
            empresas.insert(i, empresaEscolhida);
        }
    }
}

void listarFuncionarios(vector<Empresa> empresas){
    Empresa empresaEscolhida = escolherEmpresa(empresas);
    for(int i=0; i<empresaEscolhida.getTotalFuncionarios(); i++){
        cout << "print funcionarios";
    }
}

void aplicarAumento(vector<Empresa> &empresas){
    double aumento = 0.0;
    cout << "AUMENTO: " << endl;
    cin >> aumento;
    Empresa empresaEscolhida = escolherEmpresa(empresas);
    vector<Funcionario> funcionarios = empresaEscolhida.getFuncionarios();
    for (vector<Funcionario>::iterator it = funcionarios.begin(); it!=funcionarios.end(); ++it){
        it->setSalario(it->getSalario() * aumento);        
    }
}

void listarMediaFuncionarios(vector<Empresa> empresas){

}

Empresa escolherEmpresa(vector<Empresa> empresas){
    Empresa empresa;
    string nome;
    do {
        cout << "SELECIONE A EMPRESA: " << endl;
        //vectorar sobrecarregando  
        cin >> nome;
        for(vector<Empresa>::iterator it=empresas.begin(); it!= empresas.end(); ++it){
            if(it->getNome() == nome){
                empresa = *it;
            }
        }        
        if(!empresa.getNome().size()){
            cout << "Empresa inválida!" << endl;
        }
    }while(empresa.getNome().size());  
    return empresa;
}
