#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,area,p;
    printf("Please enter the 3 sides of the triangle: \n");
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a+b>c&&b+c>a&&c+a>b)
    {
        p=(a+b+c)/2;
        area=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("Area = %.2lf\nBesides,\nit is ",area);
        if(a==b&&b==c){printf("an equilateral triangle.\n");}
        else if(a==b||b==c||c==a){printf("an isosceles triangle.\n");}
        else if(a*a+b*b==c*c||b*b+c*c==a*a||c*c+a*a==b*b){printf("a right-angled triangle.\n");}
        else if(a*a+b*b<c*c||b*b+c*c<a*a||c*c+a*a<b*b)printf("an obtuse-angled triangle.\n");
        else printf("an acute-angled triangle.\n");
        printf("That's all that I can tell you.");

    }
    else printf("Illegal triangle");
    return 0;
}