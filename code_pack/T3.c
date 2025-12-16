#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int id;
    struct Node   *nxt;
};
typedef struct Node Node;
void encrypt(char* plaintext, int key, char* ciphertext)
{
    Node *entry;
    Node *p;
    Node *last;
    int cnt=0;
    int i=0;
    int n=strlen(plaintext);
    if(n==0){ciphertext[0] ='\0';return;}
    if(n==1){ciphertext[0]=plaintext[0];ciphertext[1]='\0';return;}
// #环
    entry=(Node*)malloc(sizeof(Node));
   // entry->c=plaintext[0];
    entry->id=0;
    last=entry;
    for(int i=1;i<n;++i)
    {
        p=(Node*)malloc(sizeof(Node));
   //    p->c=plaintext[i];
        p->id=i;
        last->nxt=p;
        last=p;
    }
    last->nxt=entry;
// #加密
    for(i=0;i<n;++i)
    {
        cnt=1;
        while(cnt<key)
        {
            ++cnt;
            last=entry;
            entry=entry->nxt;
        }
        
        ciphertext[entry->id]=plaintext[i];
        if(i==n-1)
        {
        free(entry);    
            break;
        }
        Node* temp=entry;
        entry=entry->nxt;
        last->nxt=entry;
        free(temp);
    }
    ciphertext[n]='\0';
}

int main(void) {
    char out[256];
    encrypt("HELLO", 2, out);
    printf("plaintext=HELLO, key=2 -> ciphertext=%s\n", out);
    encrypt("FUDANUNIVERSITY", 3, out);
    printf("plaintext=FUDANUNIVERSITY, key=3 -> ciphertext=%s\n", out);

    return 0;
}
