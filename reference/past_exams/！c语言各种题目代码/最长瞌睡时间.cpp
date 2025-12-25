#include<stdio.h>
#include<string.h>
#include<cctype>
using namespace std;
char a[100][100];
int t[100],len[100];
int n,i,ii,j,k,x,flag,T,h,m,s;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",&a[i]);
	}
	for(i=0;i<n;i++){
		len[i]=strlen(a[i]);
	}
	for(i=0;i<n;i++){
		for(ii=0;ii<len[i];ii++){	
	        if(isdigit(a[i][ii])){
	    	    if(j==0)
	    	    x+=(int)(a[i][ii]-'0');
	    	    if(j==1)
	    	    x=x*10+(a[i][ii]-'0');
	            j++;
	        }//a是数字储存到x中 ，j代表位数-1 
	        if(a[i][ii]==':'){
			    flag+=1;
			    if(flag==1)
			    t[k]+=x*3600;
			    if(flag==2)
			    t[k]+=x*60;	
			    x=0;
				j=0; 
		    }//遇到冒号说明时或分已经存到x中，把它转化为秒，再清空数据，k其实可以不要直接用i 
			if(flag==2 && j==2){
		    	t[k]+=x;
		    	k++;
				x=0;
				j=0; 
				flag=0;
			}//最后的秒不会遇到冒号，需要特殊处理 
	    }
	}
//	for(i=0;i<n;i++){
//		printf("%d\n",t[i]);
//	}
	for(i=0;i<n-1;i++)
	t[i]=t[i+1]-t[i];
//	for(i=0;i<n;i++){
//		printf("%d\n",t[i]);
//	}
	T=t[0];
	for(i=0;i<n-2;i++){
		if(t[i+1]>=t[i])
		T=t[i+1];
	}//找到最大的时间差秒数T 
//	printf("%d\n",T);
	h=T/3600;
	m=(T%3600)/60;
	s=T%60;
	printf("%d:%d:%d",h,m,s);
	return 0;
}
