#include "stdio.h"
int T;
void main()
{
	printf("%d\n", sizeof('a'));
	struct T { double x; };  // In C++, this T hides the global variable T, 
                            // but not in C
    printf("%d\n", sizeof(T));
}