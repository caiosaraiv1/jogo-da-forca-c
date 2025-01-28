#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

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

    char easy_word_one[] = "livro";
    char easy_word_two[] = "solto";
    char easy_word_three[] = "papel";
    char medium_word_one[] = "elefante";
    char medium_word_two[] = "caminhar";
    char medium_word_three[] = "computar";
    char hard_word_one[] = "conhecimento";
    char hard_word_two[] = "pluviosidade";
    char hard_word_three[] = "incontinente";

    char *easy_word[] = {easy_word_one, easy_word_two, easy_word_three};
    char *medium_word[] = {medium_word_one, medium_word_two, medium_word_three};
    char *hard_word[] = {hard_word_one, hard_word_two, hard_word_three};

    srand(time(NULL));

    printf("Digite um valor de 1-3: ");
    scanf("%d", &difficult_selected);

    switch (difficult_selected) {
    case 1:
        {
            int select = rand() % 3;
            char *selected_word = easy_word[select]; 
            int max_attempts = 8;
            printf("Voce tera %d tentativas!\n", max_attempts);
            game(selected_word, length_easy, max_attempts);
        }
        break;
    case 2:
        {
            int select = rand() % 3;
            char *selected_word = medium_word[select];
            int max_attempts = 12;
            printf("Voce tera %d tentativas!\n", max_attempts);
            game(selected_word, length_medium, max_attempts);
        }
        break;
    case 3:
        {
            int select = rand() % 3;
            char *selected_word = hard_word[select];
            int max_attempts = 15;
            printf("Voce tera %d tentativas!\n", max_attempts);
            game(selected_word, length_hard, max_attempts);
        }
        break;
    default:
        printf("Valor invalido!\n");
        break;
    }

    return 0;
}
