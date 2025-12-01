#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const char *suit[4] = {"Spades", "Heart", "Diamonds", "Clubs"};
const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const char *deck[52][2];
void init(){int i; for(i = 0; i < 52; ++i){deck[i][0] = suit[i / 13]; deck[i][1] = face[i % 13];}}
void shuffle(){int i; for(i = 0; i < 52; ++i){int r = rand() % 52; const char *t0 = deck[i][0]; const char *t1 = deck[i][1]; deck[i][0] = deck[r][0]; deck[i][1] = deck[r][1]; deck[r][0] = t0; deck[r][1] = t1;}}
void print(){int i; for(i = 0; i < 52; ++i){printf("%s-%s\n", deck[i][0], deck[i][1]);}}
int main(){srand((unsigned)time(0)); init(); shuffle(); print(); printf("---\n"); init(); shuffle(); print(); return 0;}
#include<stdio.h> 
int main()
{
   char str[1002];
   scanf("%s",str);
   char *hd;char *tl;
   char *ptr;
   hd=str;
   tl=str;
   ptr=str;
   ++ptr;
    while(*ptr!='\0')
    {
        ++tl;
        ++ptr;
    }
    while(*hd!='\0')
    {
        if(*hd!=*tl)
        {
            printf("not");
            return 0;
        }
        ++hd;
        --tl;
    }
    printf("ys");
    return 0;
}