#include<stdio.h>
int main()
{
    float score;char degree;//分数与等第
    printf("请输入百分制的成绩：");
    scanf("%f",&score);
    if(score<0||score>100){printf("输入数据错误!\n");return 0;}
    else if(score<60)degree='F';
    else if(score<70)degree='D';
    else if(score<80)degree='C';
    else if(score<90)degree='B';
    else degree='A';
    printf("成绩%.0f分，对应的等级为%c\n",score,degree);
    return 0;
}
