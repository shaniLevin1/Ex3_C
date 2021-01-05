#include <stdio.h>
#include "txtfind.h"
#include <string.h>
#define LINE 256
#define WORD 30

//this function return the number of chars in the line and save the chars in the array s
int getline1(char s[])
{
    char c = getchar();
    int i = 0;
    while (c != '\n' && c != EOF && i!=256)
    {
        s[i] = c;
        i++;
        c = getchar();
    }
    s[i] = '\0';
    if (c == EOF)
    {
        return EOF;
    }
    else
        return i;
}

//this function return the number of chars in the word and save the chars in the array w	
int getword(char w[])
{
    char c = getchar();
    int i = 0;
    while (c!='\n' && c!=' '&& c!='\t' && c!= EOF && i!=30)
    {
        w[i] = c;
        i++;
        c = getchar();
    }
    w[i]='\0';
    if(c == EOF)
    {
        return EOF;
    }
    else
        return i;
}

//this function check if str2 is contained in str1
int substring(char *str1, char *str2)
{
     int len1 = strlen(str1); 
     int len2 = strlen(str2); 

     int i=0;
     int counter=0;
  for(int j=0; j<len1; j++){
    if(str1[j]==str2[i]){
       counter++;
       i++;
       if(counter==len2)
          return 1;
      }
     else{
      counter=0;
      i=0;
     }
    if(counter==len2)
      return 1;
}
    if(counter==len2)
       return 1;
    else 
       return 0;
}

//this function print the given line if the given string is contained in the array s
void print_lines(char *str)
{
    char s[LINE];
    while (getline1(s) != EOF)
    {
        if ((substring(s, str) == 1)) //if str is contained in s
        {
            printf("%s\n", s); //print the arrray s 
        }
    }
}


int similar(char *s, char *t, int n)
{
    if(strcmp(s,t)==0)
        return 1;

    int counter=0;
    int i=0;
    int j=0;
    while(*(t + i)!='\0' || *(s + j) != '\0')
    {
        if (*(t + i) == *(s + j))
        {
            i++;
            j++;
        }
        else
        {
            j++;
            counter++;
        }
    }
    
    if (counter > n)
        return 0;
    
    else
        return 1;
}

void print_similar_words(char *str)
{
    char w[WORD];
    while (getword(w)!=EOF)
    {
        if (similar(w,str,1))
        {
            printf("%s\n",w);
        }
    }
}
