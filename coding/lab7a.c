#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
	if(n==1)
		return 1;

	else 
		return n*fact(n-1);
}

main(int argc, char* argv[])
{
	int n=atoi(argv[1]);
	int r=fact(n);

	printf("%d",r);
}