# Jogo da Forca em C

Este projeto é uma implementação do clássico jogo da forca, desenvolvida na linguagem C. O jogo permite que o jogador escolha o nível de dificuldade, tente adivinhar palavras, e exibe informações sobre as tentativas e progresso durante o jogo.

## Funcionalidades

- Três níveis de dificuldade:
  - **Fácil**: palavras com 5 letras e 8 tentativas disponíveis.
  - **Médio**: palavras com 8 letras e 12 tentativas disponíveis.
  - **Difícil**: palavras com 12 letras e 15 tentativas disponíveis.
- Seleção aleatória de palavras para cada dificuldade.
- Exibição do progresso da palavra conforme as letras são adivinhadas.
- Verificação automática de vitória ou derrota.
- Exibição do número de tentativas utilizadas.

## Estrutura do Código

O projeto está organizado em funções para garantir clareza e modularidade:

- **`verify_end_game`**: Verifica se o jogo terminou, seja por acerto completo da palavra ou por atingir o número máximo de tentativas.
- **`verify_letter`**: Verifica se a letra fornecida pelo jogador está presente na palavra e atualiza o estado do progresso.
- **`print_word`**: Imprime a palavra no estado atual.
- **`game`**: Função principal que controla a lógica do jogo, incluindo entrada do jogador, verificação de progresso e controle de tentativas.
- **`main`**: Responsável pela seleção de dificuldade, inicialização do jogo e escolha aleatória da palavra.

## Como Jogar

1. Compile o código utilizando um compilador C (como `gcc`). Exemplo:
   ```bash
   gcc -o jogo_forca jogo_forca.c
   ```
2. Execute o programa:
   ```bash
   ./jogo_forca
   ```
3. Escolha o nível de dificuldade digitando um valor de 1 a 3:
   - 1: Fácil
   - 2: Médio
   - 3: Difícil
4. Tente adivinhar as letras da palavra digitando uma letra por vez.
5. O jogo terminará quando você acertar a palavra ou atingir o número máximo de tentativas.

## Exemplo de Execução

```
Digite um valor de 1-3: 2
Voce tera 12 tentativas!
Digite uma letra: e
_ e _ e _ _ _ e
Tentativas: 1
Digite uma letra: a
_ e _ e _ a _ e
Tentativas: 2
...
Parabens, voce ganhou!
```

## Requisitos

- Compilador C (como `gcc`).
- Sistema operacional com terminal ou console.



