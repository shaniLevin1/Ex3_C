#include <stdio.h>
#include "txtfind.h"
#include <string.h>
#define WORD 30


int main(){

char arr[WORD];
getword(arr);
char ch;
scanf(" %c", &ch);

getchar();
getchar();

if(ch=='a'){
print_lines(arr);
}
if(ch=='b'){
print_similar_words(arr);
}
}
