#include <stdio.h>
main(){
	int i,n;
	float a[50],s;
	
	printf("nhap n: ");
	scanf("%d",&n);
	for (i=1;i<=n; i++){
		printf("nhap so thu nhat %d: ",i);
		scanf("%f",&a[i]);
	}
	
	printf("In so day so vua nhap ");
	for (i=1; i<=n; i++)
		printf("%.2f \t",a[i]);
		
	s=0;
	for (i=1; i<=n; i++ ){
		s=s+ a[i];
	}
		printf("\nTong cua day so vua nhap la %.3f :",s);
}

