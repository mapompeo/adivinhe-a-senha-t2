#include <iostream>
using namespace std;

void menuFuncionar();

void menu() {
    system("cls");
    cout << "-------------------------" << endl
         << "    MENU    " << endl
         << "-------------------------" << endl
         << "(1) Jogar" << endl
         << "(2) Dificuldade" << endl
         << "(3) Sobre" << endl
         << "(4) Fim" << endl
         << "-------------------------" << endl
         << endl;

    menuFuncionar();
}

void menuFuncionar() {
    int opcaoMenu;

    cout << "Digite o número que deseja ir: ";
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
            cout << "Opção Inválida, digite novamente!";
            break;
    }
}
