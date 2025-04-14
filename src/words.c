#include "wordle.h"

int NUMBER_WORDS = 5350;

char* getWord() {
    srand(time(NULL));
    int r = rand() % NUMBER_WORDS;

    FILE * fh = fopen("br-sem-acentos5.txt", "r");
    char * word = (char*)malloc(sizeof(char)*20);
    char * line = (char*)malloc(sizeof(char)*20);
    int i = 0;

    while(fgets(line, sizeof(line), fh) != NULL){
        if(i == r) {
            strcpy(word, line);
        }
        i++;
    } 

    fclose(fh);

    free(line);

    return word;
}

int startGame(char * correctWord) {
    int i, j;
    int * resposta = (int*)malloc(sizeof(int)*5);
    int tentativas = 6;
    _Bool acertou = 1; 
    _Bool valido = 0;
    char * wordsIndex = (char*)malloc(sizeof(char)*26);
    for(i = 0; i < 26; i++) {
        wordsIndex[i] = 0;
    }

    while(tentativas > 0) {
        valido = 0;
        char playerWord[10];
        acertou = 1;

        while(!valido) {
            for(i = 0; i < 10; i++) {
                playerWord[i] = '0';
            }
            valido = 1;
            printf("Digite uma palavra com 5 letras:\n");
            scanf("%s", playerWord);

            if(playerWord[5] != '\0') {
                valido = 0;
            }else{
                for(i = 0; i < 5; i++) {
                    if(playerWord[i] == '0') {
                        valido = 0;
                    }
                }
            }
        }
        

        resposta = checkWord(correctWord, playerWord, resposta);

        printWordAnwser(playerWord, resposta);

        for(i = 0; i < 5; i++) {
            if(resposta[i] != 1) {
                acertou = 0;
            }
        }

        if(acertou) {
            return 1;
        }else{
            printAlphabet(resposta, playerWord, wordsIndex); 
        }
        tentativas--;
        
    }

    free(resposta);
    free(wordsIndex);

    return 0;
}

int* checkWord(char * correctWord, char * playerWord, int * resposta){
    int i, j;
    
    for(i = 0; i < 5; i++) {
        resposta[i] = -1;
    }

    // Check for green 
    for(i = 0; i < 5; i++) {
        if (correctWord[i] == playerWord[i]) {
            resposta[i] = 1;
        }
    }

    // Check for yellow
    for(i = 0; i < 5; i++) {
        if(resposta[i] == 1) continue;
        for(j = 0; j < 5; j++) {
            if(resposta[j] == 2) continue;
            if(correctWord[i] == playerWord[j] && j != i && resposta[j] == -1) {
                resposta[j] = 2;
                break;
            }
        }
    }

    return resposta;
}

void printWordAnwser(char * playerWord, int * resposta) {
    int i;
    for(i = 0; i < 5; i++) {
        if(resposta[i] == 1) {
            printf("\033[0;32m %c \033[0m", playerWord[i]);
        }else if (resposta[i] == 2) {
            printf("\033[0;33m %c \033[0m", playerWord[i]);
        }else{
            printf("\033[0;31m %c \033[0m", playerWord[i]);
        }
    }printf("\n");
}

void printAlphabet(int * resposta, char * correctWord, char * wordsIndex) {
    int i, j;
    char alphabet[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 26; j++) {
            if(correctWord[i] == alphabet[j]) {
                if(resposta[i] == 1) {
                    wordsIndex[j] = 1;
                }else if(resposta[i] == 2 && wordsIndex[j] != 1) {
                    wordsIndex[j] = 2;
                }else if(resposta[i] == -1 && wordsIndex[j] == 0) {
                    wordsIndex[j] = -1;
                }
            }
        }
    }

    for(i = 0; i < 26; i++) {
        if(wordsIndex[i] == 1) {
            printf("\033[0;32m %c \033[0m", alphabet[i]);
        }else if (wordsIndex[i] == 2) {
            printf("\033[0;33m %c \033[0m", alphabet[i]);
        }else if (wordsIndex[i] == -1) {
            printf("\033[0;31m %c \033[0m", alphabet[i]);
        }else {
            printf(" %c ", alphabet[i]);
        }

        if(i == 9) {
            printf("\n ");
        }else if(i == 18) {
            printf("\n  ");
        }
    }printf("\n");
}
