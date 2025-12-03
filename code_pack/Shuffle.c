#include<stdio.h>
#include<stdlib.h>
#include<time.h>
const char *suit[4]=
{
    "Spades","Heart","Diamonds","Clubs"
};
//字符串常量存储位置不一定连续，但指向它们的指针数组必定连续
const char *face[13]=
{
    "Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"
};
const char* deck[52][2];
void init()
{
    int i;
    for(i=0;i<52;++i)
    {
        deck[i][0]=suit[i%4];
        deck[i][1]=face[i/13];
    }
}
void shuffle()
{
    int i;
    for(i=0;i<52;++i)
    //纯正的洗牌函数是i随机与(i,52)中的一张牌交换
    {
        int r=rand()%52; 
        const char *t0=deck[i][0];
        const char *t1=deck[i][1];
        //swap
        deck[i][0]=deck[r][0];
        deck[i][1]=deck[r][1];
        deck[r][0]=t0;
        deck[r][1]=t1;
    }

}
void print()
{
    int i; 
    for(i=0;i<52;++i)
    {
        printf("%s-%s\n", deck[i][0], deck[i][1]);
        /*
- `face[0]` 的类型是 `const char*`，它指向以 '\0' 结尾的字符串常量；`%s` 需要的正是“指向字符的指针”（字符串起始地址）。
- `*face[0]` 的类型是 `char`，只是那个字符串的第一个字符（比如 'A'）。把一个 `char` 传给 `%s` 会造成未定义行为。
因此：
- 打印整条字符串到 '\0'：`printf("%s\n", face[0]);`
- 如果只想打印第一个字符：`printf("%c\n", *face[0]);`
        */
    }
}
int main()
{
    srand((unsigned)time(0));
    init();
    shuffle();
    print();
    printf("----------------------------------\n");
    init();
    shuffle();
    print();
    return 0;
}
