#include "wordle.h"

int main() {
    char * word;

    word = getWord();

    if(startGame(word)) {
        printf("PARABENS VOCE GANHOU!!!!!!!\n");
    }else {
        printf("NÃO FOI DESSA VEZ :(\nA PALAVRA ERA %s", word);
    }

    free(word);

    return 0;
}