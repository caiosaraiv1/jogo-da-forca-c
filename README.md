# Jogo da Forca em C

Este projeto é uma implementação do clássico jogo da forca, desenvolvido na linguagem C. O jogo permite que o jogador escolha o nível de dificuldade, tente adivinhar palavras e exibe informações sobre as tentativas e o progresso durante o jogo. Agora com palavras em arquivos separados por dificuldade e uma interface de introdução para uma experiência mais interativa.

## Funcionalidades

- **Três níveis de dificuldade:**
  - **Fácil**: palavras com 5 letras e 18 tentativas disponíveis.
  - **Médio**: palavras com 8 letras e 22 tentativas disponíveis.
  - **Difícil**: palavras com 12 letras e 28 tentativas disponíveis.

- **Arquivos de palavras:**  
  Cada nível de dificuldade possui um arquivo com 100 palavras aleatórias para tornar o jogo mais variado e desafiador.

- **Interface interativa:**  
  Uma tela inicial que apresenta o jogo, suas regras e permite ao jogador escolher o nível de dificuldade.

- **Exibição do progresso:**  
  O jogo exibe o progresso da palavra conforme as letras são adivinhadas.

- **Verificação automática de vitória ou derrota:**  
  O jogo termina quando a palavra é adivinhada ou quando o número máximo de tentativas é atingido.

- **Contagem de tentativas:**  
  O número de tentativas feitas pelo jogador é mostrado durante o jogo.

## Estrutura do Código

O projeto está organizado em funções para garantir clareza e modularidade:

- **introduce_game:** Exibe a tela inicial do jogo, com regras e opções de dificuldade.
- **verify_end_game:** Verifica se o jogo terminou, seja por acerto completo da palavra ou por atingir o número máximo de tentativas.
- **verify_letter:** Verifica se a letra fornecida pelo jogador está presente na palavra e atualiza o estado do progresso.
- **print_word:** Imprime a palavra no estado atual.
- **game:** Função principal que controla a lógica do jogo, incluindo entrada do jogador, verificação de progresso e controle de tentativas.
- **main:** Responsável pela seleção de dificuldade, inicialização do jogo e escolha aleatória da palavra do arquivo correspondente.

## Como Jogar

1. Compile o código utilizando um compilador C (como `gcc`):

   ```
   gcc -o jogo_forca jogo_forca.c
   ```

2. Execute o programa:

   ```
   ./jogo_forca
   ```

3. Escolha o nível de dificuldade digitando um valor de 1 a 3:
   - 1: Fácil
   - 2: Médio
   - 3: Difícil

4. O jogo irá carregar uma palavra aleatória do arquivo correspondente à dificuldade escolhida.

5. Tente adivinhar as letras da palavra digitando uma letra por vez.

6. O jogo terminará quando você acertar a palavra ou atingir o número máximo de tentativas.

## Exemplo de Execução

```
======================================
       BEM-VINDO AO JOGO DA FORCA     
======================================
Regras do jogo:
- Voce deve adivinhar a palavra secreta, letra por letra.
- Se errar muitas vezes, voce perde!

Escolha um nivel de dificuldade:
1 - Facil   (Palavras curtas, mais tentativas)
2 - Medio   (Palavras moderadas, tentativas equilibradas)
3 - Dificil (Palavras longas, menos tentativas)

Digite o numero correspondente a dificuldade desejada e divirta-se!

Selecione a dificuldade digitando um numero de 1-3: 2
Voce tera 22 tentativas!
Digite uma letra: e
_ e _ e _ _ _ e
Tentativas: 1
Digite uma letra: a
_ e _ e a _ _ e
Tentativas: 2
...
Parabens, voce ganhou!
```

## Requisitos

- Compilador C (como `gcc`).
- Sistema operacional com terminal ou console.
- Arquivos de palavras (`easy_words.txt`, `medium_words.txt`, `hard_words.txt`) para o jogo funcionar corretamente.
