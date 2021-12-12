#include <stdio.h>
float Tong(int n)
{
	if (n==1)
		return 1;
	else
		return Tong(n-1) +1/(1.0*n);
}
main()
{
int a;
printf("Nhap a=");
scanf("%d",&a);
printf("tong la %f", Tong(a));
}
