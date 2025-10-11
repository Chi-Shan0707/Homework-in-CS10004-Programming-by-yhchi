#include<stdio.h>
int main()
{ 
    char s;//性别sex[其实应该是gender]
    float h,w;//height,weight
    float bw,bmi;//标准weight,bmi
    printf("\t***** 这是一个测试成人体重标准的程序 *****\n\n");
    printf("请输入您的性别（M 表示男性，F 表示女性）: ");
    scanf("%c",&s); //输入sex
    printf("请输入您的身高（CM）: ");
    scanf("%f",&h);//输入height
    printf("请输入您的体重（KG）: ");
    scanf("%f",&w); //输入weight

    //开始计算
    bmi=w/(h*h)*10000;//BMI=体重/身高平方
     
    bw=(s=='M'||s=='m')?(h-100)*0.95:(h-100)*0.90;
    //男性的标准体重=(身高-100)×0.95
    //女性的标准体重=(身高-100)×0.9
    printf("标准体重为：%0.2f\t 体重指数 BMI= %0.2f\n",bw, bmi);
//\t: 制表符，创造水平间距
    if(bmi<18.5)printf("体重偏瘦\n");
    if(bmi>=18.5&&bmi<24.0)printf("体重正常\n");
    if(bmi>=24.0&&bmi<27.0)printf("体重超重\n");
    if(bmi>=27.0&&bmi<30.0)printf("轻度肥胖\n");
    if(bmi>=30.0&&bmi<35.0)printf("中度肥胖\n");
    if(bmi>=35.0)printf("重度肥胖\n");
    return 0;
}