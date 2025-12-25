#include<stdio.h>
#include<math.h>
int main(){
	int s=1;
	double pi=0,n=1.0,t=1.0;
	
	while (fabs(t)>1e-6){
		pi+=t;
		n+=2;
		s=-s;
		t=s/n;
	}
	printf("%lf",4*pi);
}
