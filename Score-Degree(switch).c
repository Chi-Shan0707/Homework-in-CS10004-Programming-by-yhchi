#include<stdio.h>
int main()
{
    float score;char degree;//分数与等第
    printf("请输入百分制的成绩：");
    scanf("%f",&score);
    if(score<0||score>100){printf("输入数据错误!\n");return 0;}
    switch((int)score/10)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:/*<=59*/
            degree='F';
            break;
        case 6:/*60<=69*/
            degree='D';
            break;
        case 7:/*70<=79*/
            degree='C';
            break;
        case 8:/*80<=89*/
            degree='B';
            break;
        case 9:
        case 10:/*90<=100*/
            degree='A';
            break;
        default://其实这里的default不会执行，因为已经在第7行判断过了
            ;
    }
    printf("成绩%.0f分，对应的等级为%c\n",score,degree);
    return 0;
}