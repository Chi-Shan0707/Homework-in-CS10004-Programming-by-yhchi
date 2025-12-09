#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DECK_SIZE 52
#define MAX_PLAYERS 4
#define MAX_CARDS_PER_PLAYER 52

/* 0-3: 梅花,方片,红桃,黑桃; 1-13: A,2,...,K */
struct Card
{
    int suit;
    int face;
};
typedef struct Card Card;

const char *suit_names[]={"Clubs","Diamonds","Hearts","Spades"};
const char *rank_names[]={"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};

void init_deck(Card deck[])
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

/* Fisher-Yates 洗牌 */
void shuffle(Card deck[],int n)
{
    for(int i=n-1;i>0;i--)//正宗洗牌算法，从后往前遍历，只考虑和之前的交换
    {
        int j=rand()%(i+1);
        swap_Card(&deck[i],&deck[j]);
    }
}

void print_Card(const Card *c)
{
//传入指针
    printf("%s-%s",suit_names[c->suit],rank_names[c->face]);
}

/* 发牌: deck 中前 nCards 张牌按一轮轮发给 nPlayers 人 */
void deal(const Card deck[],int nCards,int nPlayers,int cardsPerPlayer,
          Card hands[][MAX_CARDS_PER_PLAYER])
{
    int idx=0;
    for(int r=0;r<cardsPerPlayer;r++)
    {
        for(int p=0;p<nPlayers;p++)
        {
            if(idx>=nCards) return;
            hands[p][r]=deck[idx++];
        }
    }
}

/* 返回负数: a<b; 0: 相等; 正数: a>b
   先比点数, 再比花色 */
int compare_Card(Card a,Card b)
{
    if(a.face!=b.face) return a.face-b.face;
    return a.suit-b.suit;
}

void print_hand(const Card hand[],int cnt,int playerId)
{
    printf("Player %d: ",playerId+1);
    for(int i=0;i<cnt;i++)
    {
        print_card(&hand[i]);
        if(i<cnt-1) printf(" ");
    }
    printf("\n");
}

int main()
{
    Card deck[DECK_SIZE];
    Card hands[MAX_PLAYERS][MAX_CARDS_PER_PLAYER];

    int nPlayers;
    printf("输入玩家人数(3或4): ");
    scanf("%d",&nPlayers);
    if(nPlayers!=3 && nPlayers!=4)
    {
        printf("只支持3或4人。\n");
        return 0;
    }

    int cardsPerPlayer=DECK_SIZE/nPlayers;

    srand((unsigned int)time(NULL));

    init_deck(deck);
    shuffle(deck,DECK_SIZE);
    deal(deck,DECK_SIZE,nPlayers,cardsPerPlayer,hands);

    for(int p=0;p<nPlayers;p++)
    {
        print_hand(hands[p],cardsPerPlayer,p);
    }

    /* 示例比较：比较第1个人的前两张牌 */
    if(cardsPerPlayer>=2)
    {
        Card c1=hands[0][0];
        Card c2=hands[0][1];
        printf("比较 Player1 的前两张: ");
        print_Card(&c1);
        printf(" vs ");
        print_Card(&c2);
        int r=compare_Card(c1,c2);
        if(r<0) printf(" -> 第二张更大\n");
        else if(r>0) printf(" -> 第一张更大\n");
        else printf(" -> 两张相等\n");
    }

    return 0;
}