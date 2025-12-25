#include<stdio.h>
#define JudgeLeapYear(year) (((year)%4==0&&(year)%100!=0)||(year)%400==0)
int main()
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    if(JudgeLeapYear(year))printf("%d is a leap year.\n", year);
    else printf("%d is not a leap year.\n", year);
    return 0;
}