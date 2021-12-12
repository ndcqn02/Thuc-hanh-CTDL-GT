#include <stdio.h>
int Tong(int n)
{
	if (n==1)
		return -1;
	if (n%2!=0)
		return -n+Tong(n-1);
	else
		return n+Tong(n-1);
}
main()
{
int a;
printf("Nhap a=");
scanf("%d",&a);
printf("tong la %d", Tong(a));
}
