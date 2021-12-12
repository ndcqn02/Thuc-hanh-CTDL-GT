#include <stdio.h>
int tru2so(int x, int *y){
	*y=*y-x;
	x=x-*y;
	return(x-*y);
}
main ()
{
	int c=3, k=-2, e;
	e=tru2so(k,&c);
	printf("c=%d\t ", c);
	printf("k=%d\t ",k);
	printf("e=%d\t",e);
	
}
