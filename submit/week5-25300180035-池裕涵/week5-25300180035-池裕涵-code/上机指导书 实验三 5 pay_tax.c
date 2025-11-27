#include<stdio.h>
int main()
{
    float x,y;
    printf("---------------------------------\n");
    printf("\t 个人所得税计算器 \n\n\n");
    printf("请输入您的薪酬总金额(其中免税金额为3500元：");
    scanf("%f",&x);
    if(x<=3500)                                  /*低于 3500 免税*/
    {
        printf("您输入的薪酬金额低于3500元，无需交个人所得税!\n");
        return 0;
    }
    x=x-3500;
    //x 为应税额
    switch((int)(x/1500))
    {
        case 0://错误在次
        case 1:
        //≤1500
            y=0.03*x;
            break;
        case 2:
        case 3:
        //≤4500
            y=x*0.10-105;
            break;
        case 4:
        case 5:
        case 6:
        //≤9000
            y=x*0.20-555; break;
        default:
            y=x*0.25-1005;
    }
    printf("您的应税额为：%.2f，\n应交个人所得税为：%.2f\n",x,y);
    return 0;
}