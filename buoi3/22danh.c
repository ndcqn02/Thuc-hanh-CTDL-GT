#include<stdio.h>
#include<math.h>
int TinhT(int n)
{
	if (n==1)
		return 1;
	else
		return (TinhT(n-1)+pow(-1,1+n)*n);
}
int main()
{
	int n;
	printf(" nhap n :");
	scanf("%d",&n);
	printf("%d",TinhT(n));
}
