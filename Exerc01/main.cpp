#include <iostream>
using namespace std;

int opcaoMenu;
string clientes[5];

void mostrarMenu();
void cadastrar();
void pesquisar();
void exibir();
void excluir();

int main()
{
    mostrarMenu();
}

void mostrarMenu(){
    do{
        system("cls");
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Pesquisar" << endl;
        cout << "3 - Excluir" << endl;
        cin >> opcaoMenu;

        switch (opcaoMenu)
        {
            case 1: cadastrar();
                break;
            case 2: pesquisar();
                break;
            case 3: excluir();
                break;

            default:
                cout << "Opcao Invalida" << endl;
        }
	    system("pause");
    }
    while (opcaoMenu > 3);
}

void cadastrar(){
    for(int i = 0; i < 5; i++){
        if(clientes[i] == ""){
            do{
                cout << "Informe o "<< i+1 << "o nome do cliente: ";
                cin >> clientes[i];
            }
            while(clientes[i] == "");
        }
    }

    cout << "\nUsuarios cadastrados com sucesso" << endl;
    cout << endl;
	system("pause");
    mostrarMenu();
}

void pesquisar(){
    string nomePesquisar;
    int indiceSucesso = -1;

    do{
        cout << "Informe o nome do cliente a pesquisar: ";
        cin >> nomePesquisar;
    }
    while(nomePesquisar == "");

    for(int i = 0; i < 5; i++){
        if(clientes[i] == nomePesquisar){
            indiceSucesso = i;
            break;
        }
    }

    if(indiceSucesso == -1){
        cout << "\nCliente nao encontrado" << endl;
    }
    else{
        cout << "\nCliente encontrado na posicao " << indiceSucesso << endl;
    }

    cout << endl;
	system("pause");
    mostrarMenu();
}

void exibir(){
    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << "Indice " << i << " - " << (clientes[i] == "" ? "Vazio" : clientes[i]) << endl;
    }
    cout << endl;
}

void excluir(){
    int indiceExcluir;
    exibir();

    do{
        cout << "Informe o indice a excluir: ";
        cin >> indiceExcluir;
    }
    while(indiceExcluir < 0 || indiceExcluir > 5);

    if(indiceExcluir > 5 || indiceExcluir < 0){
        cout << "Indice invalido" << endl;
    }
    else{
        clientes[indiceExcluir] = "";
        cout << "\nIndice " << indiceExcluir <<" excluido com sucesso" << endl;
    }

    cout << endl;
	system("pause");
    mostrarMenu();
}