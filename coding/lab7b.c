#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int gcd(int n, int m)
{
	
	if(n%m==0)
		return m;
	else
		return gcd(m,n%m);
	
}

main(int argc, char* argv[])
{
	int n=atoi(argv[1]);
	int m=atoi(argv[2]);

	if(n<m)
		swap(&n,&m);

	int r=gcd(n,m);

	printf("%d\n",r);
}