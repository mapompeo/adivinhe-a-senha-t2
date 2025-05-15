#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void jogar();
void menu();
void menuFuncionar();
void voltarFechar();
void dificuldade();
void sobre();
void fim();
void gerarSenha(int dificuldade);

// Variáveis globais
int nivelDificuldade = 2;  // 1 = fácil, 2 = médio (padrão), 3 = difícil
int v1, v2, v3, v4, v5;     // Dígitos da senha secreta

void menuFuncionar() {
    int opcaoMenu;
    cout << "Digite a opcao que deseja ir: ";
    cin >> opcaoMenu;

    switch (opcaoMenu) {
        case 1: jogar(); break;
        case 2: dificuldade(); break;
        case 3: sobre(); break;
        case 4: fim(); break;
        default:
            cout << "Opcao invalida, digite novamente!" << endl;
            menuFuncionar();
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
         << "+-----------------+" << endl << endl;

    menuFuncionar();
}

void voltarFechar() {
    cout << "+-----------------------+" << endl
         << "|          MENU         |" << endl
         << "+-----------------------+" << endl
         << "| (1) Voltar            |" << endl
         << "| (0) Fechar o programa |" << endl
         << "+-----------------------+" << endl << endl;

    int opcaovoltarFechar;
    cout << "Digite a opcao que deseja ir: ";
    cin >> opcaovoltarFechar;

    switch (opcaovoltarFechar) {
        case 1: menu(); break;
        case 0: fim(); break;
        default:
            cout << "Opcao invalida, digite novamente!" << endl;
            voltarFechar();
            break;
    }
}

// Função principal do jogo
void jogar() {
    system("cls");
    int digitos, tentativas;

    // Define a quantidade de dígitos e tentativas conforme a dificuldade
    switch (nivelDificuldade) {
        case 1: digitos = 3; tentativas = 8; break;
        case 2: digitos = 4; tentativas = 10; break;
        case 3: digitos = 5; tentativas = 12; break;
    }

    cout << "INICIANDO O JOGO" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Dificuldade: " << nivelDificuldade << endl;
    cout << "Digite os numeros separados por espaco (ex: 1 2 3 4)" << endl;
    cout << "Voce precisa adivinhar uma senha de:" << endl << endl;
    cout << digitos << " digitos" << endl;
    cout << tentativas << " tentativas" << endl;
    cout << "----------------------------------------" << endl;

    gerarSenha(nivelDificuldade); // Gera senha aleatória

    cout << "Exemplo: ";
    for (int i = 0; i < digitos; i++) {
        cout << "* ";
    }
    cout << endl << "----------------------------------------" << endl << endl;

    // Variáveis para as tentativas e controle
    int tentativa1, tentativa2, tentativa3, tentativa4 = 0, tentativa5 = 0;
    int tentativasRestantes = tentativas;
    bool acertou = false;

    while (tentativasRestantes > 0 && !acertou) {
        cout << "Tentativas restantes: " << tentativasRestantes << endl;
        cout << "Digite sua tentativa: ";

        // Entrada das tentativas com base na dificuldade
        cin >> tentativa1 >> tentativa2 >> tentativa3;
        if (nivelDificuldade >= 2) cin >> tentativa4;
        if (nivelDificuldade == 3) cin >> tentativa5;

        int pretos = 0;  // Dígitos corretos na posição correta
        int brancos = 0; // Dígitos corretos na posição errada

        // Verifica posições corretas (pretos)
        if (tentativa1 == v1) pretos++;
        if (tentativa2 == v2) pretos++;
        if (tentativa3 == v3) pretos++;
        if (nivelDificuldade >= 2 && tentativa4 == v4) pretos++;
        if (nivelDificuldade == 3 && tentativa5 == v5) pretos++;

        // Verifica posições erradas (brancos)
        if (nivelDificuldade == 1) {
            if (tentativa1 != v1 && (tentativa1 == v2 || tentativa1 == v3)) brancos++;
            if (tentativa2 != v2 && (tentativa2 == v1 || tentativa2 == v3)) brancos++;
            if (tentativa3 != v3 && (tentativa3 == v1 || tentativa3 == v2)) brancos++;
        } else if (nivelDificuldade == 2) {
            if (tentativa1 != v1 && (tentativa1 == v2 || tentativa1 == v3 || tentativa1 == v4)) brancos++;
            if (tentativa2 != v2 && (tentativa2 == v1 || tentativa2 == v3 || tentativa2 == v4)) brancos++;
            if (tentativa3 != v3 && (tentativa3 == v1 || tentativa3 == v2 || tentativa3 == v4)) brancos++;
            if (tentativa4 != v4 && (tentativa4 == v1 || tentativa4 == v2 || tentativa4 == v3)) brancos++;
        } else if (nivelDificuldade == 3) {
            if (tentativa1 != v1 && (tentativa1 == v2 || tentativa1 == v3 || tentativa1 == v4 || tentativa1 == v5)) brancos++;
            if (tentativa2 != v2 && (tentativa2 == v1 || tentativa2 == v3 || tentativa2 == v4 || tentativa2 == v5)) brancos++;
            if (tentativa3 != v3 && (tentativa3 == v1 || tentativa3 == v2 || tentativa3 == v4 || tentativa3 == v5)) brancos++;
            if (tentativa4 != v4 && (tentativa4 == v1 || tentativa4 == v2 || tentativa4 == v3 || tentativa4 == v5)) brancos++;
            if (tentativa5 != v5 && (tentativa5 == v1 || tentativa5 == v2 || tentativa5 == v3 || tentativa5 == v4)) brancos++;
        }

        cout << "Corretos em posicao correta: " << pretos << endl;
        cout << "Corretos em posicao errada: " << brancos << endl;
        cout << "----------------------------------------" << endl << endl;

        // Vitória
        if (pretos == digitos) {
            cout << "Parabens, voce acertou a senha!" << endl;
            acertou = true;
        } else {
            cout << "----------------------------------------" << endl;
            tentativasRestantes--;
        }
    }

    // Caso perca, mostra a senha correta
    if (!acertou) {
        cout << "Voce perdeu! A senha era: ";
        cout << v1 << " " << v2 << " " << v3;
        if (nivelDificuldade >= 2) cout << " " << v4;
        if (nivelDificuldade == 3) cout << " " << v5;
        cout << endl;
    }

    voltarFechar();
}

// Gera a senha aleatória sem repetir os dígitos
void gerarSenha(int dificuldade) {
    v1 = (rand() % 6) + 1;
    do { v2 = (rand() % 6) + 1; } while (v2 == v1);
    do { v3 = (rand() % 6) + 1; } while (v3 == v1 || v3 == v2);

    if (dificuldade >= 2)
        do { v4 = (rand() % 6) + 1; } while (v4 == v1 || v4 == v2 || v4 == v3);
    else
        v4 = 0;

    if (dificuldade == 3)
        do { v5 = (rand() % 6) + 1; } while (v5 == v1 || v5 == v2 || v5 == v3 || v5 == v4);
    else
        v5 = 0;
}

void dificuldade() {
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
         << "+---------------------------+" << endl << endl;

    int opcaoDificuldade;
    cout << "Digite a opcao que deseja: ";
    cin >> opcaoDificuldade;

    if (opcaoDificuldade >= 1 && opcaoDificuldade <= 3) {
        nivelDificuldade = opcaoDificuldade;
        menu();
    } else {
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
         << "+--------------------------------------------------------------------------+" << endl << endl;

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
    srand(time(0));  // Inicializa gerador de números aleatórios
    menu();
    return 0;
}
