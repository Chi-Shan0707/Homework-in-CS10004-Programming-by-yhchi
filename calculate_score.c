#include<stdio.h>
int main()
{
    int n;int sc[102][3];int subject[3];
    subject[0]=subject[1]=subject[2]=0;
    scanf(" %d",&n);
    for(int i=0;i<n;++i)
    {
        scanf(" %d %d %d",&sc[i][0],&sc[i][1],&sc[i][2]);
        subject[0]+=sc[i][0];
        subject[1]+=sc[i][1];
        subject[2]+=sc[i][2];
    }
    for(int i=0;i<n;++i)
    {
        float average=(float)((sc[i][0]+sc[i][1]+sc[i][2])/3.0);
        printf("第%d个学生的平均成绩%.3f\n",i+1,average);
    }
    for(int j=0;j<3;++j)
    {
        float average=(float)(subject[j]*1.0)/(float)(n);
        printf("第%d门课的平均成绩%.3f\n",j+1,average);
    }
    return 0;
}