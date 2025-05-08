# Adivinhe a Senha - Trabalho 2 (2025/1)

## Descrição
O **Adivinhe a Senha** é uma implementação do jogo **Mastermind**, onde o jogador deve adivinhar uma sequência de números aleatórios (1-6) sem repetição, com base em dicas sobre a posição correta e incorreta dos números. O jogo possui três níveis de dificuldade: Fácil (3 dígitos), Média (4 dígitos) e Difícil (5 dígitos).

## Regras:
O jogador tem um número limitado de tentativas para descobrir a senha.
Após cada tentativa, o sistema informa quantos números estão corretos e quantos estão na posição errada.
O jogo termina quando o jogador acerta a senha ou as tentativas se esgotam.

## Menu:
- **Jogar**: Inicia o jogo.
- **Dificuldade**: Escolha entre Fácil, Média ou Difícil.
- **Sobre**: Exibe informações sobre a equipe de desenvolvimento.
- **Fim**: Encerra o jogo.

## Como rodar no Windows

### 1. Certifique-se de ter o compilador C++ instalado (como o `g++`):
   - Para isso, use o [MinGW](http://www.mingw.org/) ou o WSL (Windows Subsystem for Linux).

### 2. Baixe o código:
   - Se você ainda não clonou o repositório, faça isso com o comando abaixo:
     ```bash
     git clone https://github.com/seu-usuario/adivinhe-a-senha-t2.git
     ```

### 3. Acesse a pasta do projeto:
   - Navegue até a pasta onde o projeto foi salvo. Exemplo:
     ```cmd
     cd C:\Users\SeuUsuario\Downloads\adivinhe-a-senha-t2
     ```

### 4. Compile o programa:
   - Compile o código usando o `g++` para gerar o executável:
     ```cmd
     g++ -o adivinhe_senha.exe main.cpp
     ```

### 5. Execute o programa:
   - Por fim, execute o programa gerado:
     ```cmd
     adivinhe_senha.exe
     ```

---

## Licença

Este projeto é de uso acadêmico, desenvolvido para a disciplina **Algoritmos e Programação** da Universidade do Vale do Itajaí (UNIVALI). Todos os direitos reservados aos membros da equipe.

## Agradecimentos

Agradecemos ao professor [Michael Douglas] pela orientação e aos demais de classe pela colaboração.

---

Feito por [Matheus Pompeo](https://github.com/mapompeo) e [Nathan Reichert](https://github.com/1snxw) - UNIVALI 2025
