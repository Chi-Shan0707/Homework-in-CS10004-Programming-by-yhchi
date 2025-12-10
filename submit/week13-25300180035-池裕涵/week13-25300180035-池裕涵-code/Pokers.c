#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DECK_SIZE 52
#define MAX_PLAYERS_NUM 4
#define MAX_HAND_CARDS_NUM 52

struct Card
{
    int suit;
    int face;
};
typedef struct Card Card;
//不然 类型名就是 struct Card 了
const char *Suits[]={"Clubs","Diamonds","Hearts","Spades"};
const char *Faces[]={"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
void init(Card deck[])
{
    for(int i=0;i<DECK_SIZE;++i)
    {
        deck[i].suit=i/13;
        deck[i].face=i%13+1;
    }
}
void swap_Card(Card *a,Card *b)
{
    Card t=*a;
    *a=*b;
    *b=t;
}
void shuffle_Card(Card deck[],int n)
{
    for(int i=n-1;i>0;i--)
//正宗洗牌算法，从后往前遍历，只考虑和之前的交换
    {
        int j=rand()%(i+1);
        swap_Card(&deck[i],&deck[j]);
    }
}

void print_CardInfo(const Card *c)
{
    printf("%s-%s\n",Suits[c->suit],Faces[c->face]);
}

void deal(const Card deck[],int playerNum,int handCardNum,
          Card hands[][MAX_HAND_CARDS_NUM])
{
    int CardId=0;
    
    for(int person=0;person<playerNum;person++)
    {
        for(int handCardid=0;handCardid<handCardNum;++handCardid)
        {
            hands[person][handCardid]=deck[CardId++];
        }
    }
}

int compare_Card(Card a,Card b)
{
    return a.face-b.face;
}
void print_PlayerHand(const Card hand[],int handCardNum,int playerId)
{
    printf("##########################\n\nPlayer %d :\n ",playerId+1);
    for(int i=0;i<handCardNum;i++)
    {
        print_CardInfo(&hand[i]);
       
    }
    printf("\n");
    printf("##########################\n\n");
}
int main()
{
    Card deck[DECK_SIZE];
    Card hands[MAX_PLAYERS_NUM][MAX_HAND_CARDS_NUM];
    int cmp_res;
    int playerNum,handCardNum;
    printf("输入玩家人数( 3 or 4 ): ");
    scanf("%d",&playerNum);
    
    handCardNum=(playerNum==3)?17:13;
    srand((unsigned int)time(NULL));
    init(deck);
    shuffle_Card(deck,DECK_SIZE);

    deal(deck,playerNum,handCardNum,hands);

    for(int p=0;p<playerNum;p++)
    {
        print_PlayerHand(hands[p],handCardNum,p);
    }

    //cmp
    printf("Comparing two cards:\n");
    printf("Card 1: ");
    print_CardInfo(&deck[0]);
    printf("Card 2: ");
    print_CardInfo(&deck[1]);
    cmp_res=compare_Card(deck[0],deck[1]);
    if(cmp_res>0)
    {
        printf("Card 1 is bigger than Card 2\n");
    }
    else if(cmp_res<0)
    {
        printf("Card 1 is smaller than Card 2\n");
    }
    else
    {
        printf("Card 1 is equal to Card 2\n");
    }
    return 0;
}