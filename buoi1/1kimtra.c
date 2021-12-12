#include <stdio.h>
int tru2so(int *x, int *y){
	*y=*y-*x;
	*x=*x-*y;
	return (*x-*y);
	
}
main(){
	int c=13, k=-21,e;
	e=tru2so(&k,&c);
	printf("c= %d   k=%d    e=%d ",c,k,e);
	
}

//y=c=13  			 x=k=-21 			 e
//*y=13--21=34		*x=-21-34=-55		e=-55-34=-89
//-> c=34  k=-55	
