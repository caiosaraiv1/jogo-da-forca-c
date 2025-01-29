#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void intruceGame() {
    printf("======================================\n");
    printf("       BEM-VINDO AO JOGO DA FORCA     \n");
    printf("======================================\n");
    printf("Regras do jogo:\n");
    printf("- Voce deve adivinhar a palavra secreta, letra por letra.\n");
    printf("- Se errar muitas vezes, voce perde!\n\n");

    printf("Escolha um nivel de dificuldade:\n");
    printf("1 - Facil   (Palavras curtas, mais tentativas)\n");
    printf("2 - Medio   (Palavras moderadas, tentativas equilibradas)\n");
    printf("3 - Dificil (Palavras longas, menos tentativas)\n\n");

    printf("Digite o numero correspondente a dificuldade desejada e divirta-se!\n");
}

bool verify_end_game(int attempts, int max_attempts, char word[], int length) {
    
    bool condition_one = false;
    bool condition_two = true;
    
    if(attempts >= max_attempts) {
        condition_one = true; 
    } 

    for (int i = 0; i < length; i++) {
        if (word[i] == '_') {
            condition_two = false;
            break;
        } 
    }

    return condition_one || condition_two;
}

void verify_letter(char letter, char word[], int length, char user_input[]) {

    for(int i = 0; i < length; i++ ) {
        if(letter == word[i]) {
            user_input[i] = letter;
        }
    }
}

void print_word(char word[], int length) {

    for(int i = 0; i < length; i++) {
       printf("%c", word[i]);
    }
}

void game(char selected_word[], int length_word, int max_attempts) {

    char user_input[length_word + 1];
    for(int i = 0; i < length_word; i++) {
        user_input[i] = '_';    
    }
    user_input[length_word] = '\0';

    bool is_game_finished = false;
    int attempts = 0;

    while(!is_game_finished) {

        char user_attempt;
        printf("Digite uma letra: ");
        scanf(" %c", &user_attempt);
        verify_letter(user_attempt, selected_word, length_word, user_input);

        print_word(user_input, length_word);

        printf("\nTentativas: %d\n", attempts);

        is_game_finished = verify_end_game(attempts, max_attempts, user_input, length_word);
        attempts++;
    }

    if (attempts <= max_attempts) {
        printf("Parabens, voce ganhou!\n");
    } else {
        printf("Voce perdeu! A palavra era: %s\n", selected_word);
    }
}

int main() {

    int length_easy = 5;
    int length_medium = 8;
    int length_hard = 12;

    int difficult_selected;

    FILE *archive;
    char line[12];
    int counter = 0;
    int select_line = (rand() % 100) + 1;;

    srand(time(NULL));

    intruceGame();

    printf("Selecione a dificuldade digitando um numero de 1-3: ");
    scanf("%d", &difficult_selected);

    switch (difficult_selected) {
    case 1:
        {
            archive = fopen("easy_words.txt", "r");
            if(archive == NULL) {
                printf("Erro ao abrir o arquivo");
                return 1;
            }

            char word[5];

            while(fgets(line, 15, archive) != NULL) {
                counter++;
                if(counter == select_line) {
                    if(sscanf(line, "%s", word) != 1) {
                        printf("Nenhuma palavra na linha");
                    }
                    break;
                }
            }
 
            int max_attempts = 18;
            printf("Voce tera %d tentativas!\n", max_attempts);
            game(word, length_easy, max_attempts);
        }
        break;
    case 2:
        {
            archive = fopen("medium_words.txt", "r");
            if(archive == NULL) {
                printf("Erro ao abrir o arquivo");
                return 1;
            }

            char word[8];

            while(fgets(line, 15, archive) != NULL) {
                counter++;
                if(counter == select_line) {
                    if(sscanf(line, "%s", word) != 1) {
                        printf("Nenhuma palavra na linha");
                    }
                    break;
                }
            }

            int max_attempts = 22;
            printf("Voce tera %d tentativas!\n", max_attempts);
            game(word, length_medium, max_attempts);
        }
        break;
    case 3:
        {
            archive = fopen("hard_words.txt", "r");

            if(archive == NULL) {
                printf("Erro ao abrir o arquivo");
                return 1;
            }

            char word[12];

            while(fgets(line, 15, archive) != NULL) {
                counter++;
                if(counter == select_line) {
                    if(sscanf(line, "%s", word) != 1) {
                        printf("Nenhuma palavra na linha");
                    }
                    break;
                }
            }

            int max_attempts = 28;
            printf("Voce tera %d tentativas!\n", max_attempts);
            game(word, length_hard, max_attempts);
        }
        break;
    default:
        printf("Valor invalido!\n");
        break;
    }

    return 0;
}
