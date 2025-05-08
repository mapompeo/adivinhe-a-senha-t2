#include <iostream>
#include <time.h>

using namespace std;

void jogar();
int dificuldade();
void sobre();
void fim();


void menuFuncionar() {
    int opcaoMenu;

    cout << "Digite a opcao que deseja ir: ";
    cin >> opcaoMenu;

    switch (opcaoMenu) {
        case 1:
            jogar();
            break;
        case 2:
            dificuldade();
            break;
        case 3:
            sobre();
            break;
        case 4:
            fim();
            break;
        default:
            cout << "Opcao invalida, digite novamente!";
            break;
    }
}

void menu() {
    system("cls");
    cout << "+-----------------+" << endl
         << "|       MENU      |" << endl
         << "+-----------------+" << endl
         << "| (1) Jogar       |" << endl
         << "| (2) Dificuldade |" << endl
         << "| (3) Sobre       |" << endl
         << "| (4) Fim         |" << endl
         << "+-----------------+" << endl
         << endl;

    menuFuncionar();
}

void voltarFechar() {
    cout << "+-----------------------+" << endl
         << "|          MENU         |" << endl
         << "+-----------------------+" << endl
         << "| (1) Voltar            |" << endl
         << "| (0) Fechar o programa |" << endl
         << "------------------------+" << endl
         << endl;

    int opcaovoltarFechar;
    cout << "Digite a opcao que deseja ir: ";
    cin >> opcaovoltarFechar;

    switch (opcaovoltarFechar) {
        case 1:
            menu();
        case 0:
            fim();
        default:
            cout << "Opcao invalida, digite novamente!";
            break;
    }
}

void jogar() {

}


int dificuldade() {
    system("cls");
    cout << "+---------------------------+" << endl
         << "|        DIFICULDADE        |" << endl
         << "+---------------------------+" << endl
         << "| (1) Facil                 |" << endl
         << "| 3 digitos e 8 tentativas  |" << endl
         << "+---------------------------+" << endl
         << "| (2) Media (Padrao)        |" << endl
         << "| 4 digitos e 10 tentativas |" << endl
         << "+---------------------------+" << endl
         << "| (3) Dificil               |" << endl
         << "| 5 digitos e 12 tentativas |" << endl
         << "+---------------------------+" << endl
         << endl;

    int opcaoDificuldade, novaDificuldade;
    cout << "Digite a opcao que deseja: ";
    cin >> opcaoDificuldade;

    switch (opcaoDificuldade) {
        case 1:
            novaDificuldade = opcaoDificuldade;
            return novaDificuldade;
            voltarFechar();
        case 2:
            novaDificuldade = opcaoDificuldade;
            return novaDificuldade;
            voltarFechar();
        case 3:
            novaDificuldade = opcaoDificuldade;
            return novaDificuldade;
            voltarFechar();
        default:
            cout << "Opcao invalida, digite novamente!" << endl;
            dificuldade();
    }
}

void sobre() {
    system("cls");
    cout << "+--------------------------------------------------------------------------+" << endl
         << "|                                SOBRE                                     |" << endl
         << "+--------------------------------------------------------------------------+" << endl
         << "| Desenvolvido por:                                                        |" << endl
         << "| Matheus Pompeo Dias (github.com/mapompeo)                                |" << endl
         << "| Nathan Gustavo Padilha Reicher (github.com/1snxw)                        |" << endl
         << "+--------------------------------------------------------------------------+" << endl
         << "| Professor:                                                               |" << endl
         << "| Michael Douglas Alves (linkedin.com/in/michael-douglas-c-alves-1227a469) |" << endl
         << "| Disciplina de Algoritmos e Programacao                                   |" << endl
         << "+--------------------------------------------------------------------------+" << endl
         << "| Data:                                                                    |" << endl
         << "| Maio/2025                                                                |" << endl
         << "+--------------------------------------------------------------------------+" << endl
         << endl;

    voltarFechar();
}

void fim() {
    system("cls");
    cout << "+----------------------------------------------------------------+" << endl
         << "|                         OBRIGADO!                              |" << endl
         << "+----------------------------------------------------------------+" << endl
         << "| Muito obrigado por jogar \"Adivinhe a Senha\"!                   |" << endl
         << "| Desenvolvido para a disciplina de Algoritmos e Programacao     |" << endl
         << "| UNIVALI - Campus Itajai | Ciencia da Computacao | Turma 2025/1 |" << endl
         << "+----------------------------------------------------------------+" << endl;

    exit(0);
}

int main() {
    menu();
    return 0;
}
