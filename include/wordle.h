#ifndef WORDLE_H
#define WORDLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern int NUMBER_WORDS;

char* getWord();
int startGame(char * word);
int* checkWord(char * correctWord, char * playerWord, int * resposta);
void printWordAnwser(char * playerWord, int * resposta);
void printAlphabet(int * resposta, char * correctWord, char * wordsIndex);

#endif


