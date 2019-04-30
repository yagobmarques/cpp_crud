#include "menu.h"

void iniciarMenu(){
    int option;
    cout << "Bem vindo!" << endl;
    list<Empresa> empresas;
    list<Funcionario> funcionarios;
    do{        
        option = escolherOpcao();       
        switch(option){
            case 1: {
                Empresa empresa = criarEmpresa();
                if(checarEmpresa(empresas, empresa)){
                    empresas.push_back(empresa);
                    cout << empresa;
                    mensagemSucesso("Empresa cadastrada com sucesso!");
                    break;
                }
                mensagemErro("Essa empresa já existe");
                break;
            }
                
            case 2: {
                Funcionario funcionario = criarFuncionario();
                if(checarFuncionario(empresas, funcionario)) {
                    adicionarFuncionario(&empresas, funcionario);
                    funcionarios.push_back(funcionario);
                    mensagemSucesso("Funcionário adicionado com sucesso!");
                    break;
                }
                mensagemErro("Funcionário já existe!");
                break;
            }                
            case 3:
                listarFuncionarios(&empresas);
                break;
            case 4:
                aplicarAumento(&empresas);
                mensagemSucesso("Aumento aplicado com sucesso!");
                break;
            case 5:
                listarMediaFuncionarios(empresas);
                break;
            default:
                break;
        }       
    }while(option != 0);    
}

int escolherOpcao(){
    set<int> options = {0,1,2,3,4,5,6};
    int op;
    cout <<CYAN<< "--- MENU PRINCIPAL ---"<<RESET<< endl;
    cout << "1 - criar empresa" << endl;
    cout << "2 - adicionar funcionário" << endl;
    cout << "3 - listar funcionarios" << endl;
    cout << "4 - aplicar aumento" << endl;
    cout << "5 - listar média de funcionários" << endl;
    cout << "0 - sair"<<endl;
    cin >> op;
    const bool opValida = options.find(op) != options.end();
    if (opValida){
        return op;
    } else {
        cout << RED << "Opção inválida!" << RESET<< endl;
        return -1;
    }
}
bool checarEmpresa(list<Empresa> empresas, Empresa empresa){
    for(auto &e: empresas){
        if(e.getCnpj() == empresa.getCnpj()){
            return false;
        }
    }
    return true;
}
bool checarFuncionario(list<Empresa> empresas , Funcionario funcionario){
    for(auto &e: empresas){
        for(auto &f: e.getFuncionarios()){
            if(f.getNome() == funcionario.getNome() && f.getSalario() == funcionario.getSalario()){
                return false;
            }
        }
    }
    return true;
}
void mensagemSucesso(string mensagem){
    cout << GREEN << mensagem << RESET << endl;
}
void mensagemErro(string mensagem){
    cout << RED << mensagem << RESET << endl;
}
