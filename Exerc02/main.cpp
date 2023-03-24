#include <iostream>
using namespace std;

string gabarito[10];
string resposta;
int opcaoMenu, notaFinal;

void mostrarMenu();
void cadastrarGabarito();
void cadastrarProva();
void verificarSituacao(int valor);

int main()
{
    mostrarMenu();
}

void mostrarMenu(){
    do{
        system("cls");
        cout << "1 - Cadastrar Gabarito" << endl;
        cout << "2 - Cadastrar Prova" << endl;
        cout << "3 - Sair" << endl;
        cin >> opcaoMenu;

        switch (opcaoMenu)
        {
            case 1: cadastrarGabarito();
                break;
            case 2: cadastrarProva();
                break;

            default:
                cout << "Opcao Invalida" << endl;
        }
        system("pause");
    }
    while(opcaoMenu > 3);
}

void cadastrarGabarito(){
    for(int i = 0; i < 10; i++){
        cout << "Informe a resposta da questao " << (i+1) << ": ";
        cin >> gabarito[i];
        cout << endl;
    }

    cout << endl;
    system("pause");
    mostrarMenu();
}

void cadastrarProva(){
    int nota = 0;
    int resultado;
    for(int i = 0; i < 10; i++){
        cout << "Informe a resposta da questao " << (i+1) << ": ";
        cin >> resposta;
        cout << endl;

        if(resposta == gabarito[i]){
            nota += 1;
        }
    }
    resultado = nota;
    system("pause");

    verificarSituacao(resultado);
}

void verificarSituacao(int nota){
    if(nota >= 7){
        cout << endl << "Aprovado" << endl;
        cout << "Nota " << nota << endl;
    }
    else{
        cout << endl << "Reprovado" << endl;
        cout << "Nota " << nota << endl;
    }
    
    cout << endl;
    system("pause");
    mostrarMenu();
}