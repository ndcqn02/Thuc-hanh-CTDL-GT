#include <stdio.h>
	int n,i;
void NHAP_DS (float dss[], int n){
	for (i=1;i<=n; i++){
	
		printf("nhap ptu thu %d ",i);
		scanf("%f",&dss[i]);
	}
}

void IN_DS( float ds[], int n) {
	printf("in day so \n ");
	for (i=1;i<=n; i++)
		printf("%f  ",ds[i]);
}
main ()
 {
 	float ds[100];
 
	printf("day co bao nhieu so n:= ");
	scanf("%d ", &n);
	
	NHAP_DS (&ds,n);
	IN_DS(&ds,n);
}
