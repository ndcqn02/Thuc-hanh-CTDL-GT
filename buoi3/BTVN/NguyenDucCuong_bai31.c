//bai 31 tinh tong cac phan tu trong mang
#include <stdio.h>
void Nhap(int a[], int n){
//	for( int i=1; i<n; i++){
//		printf("Nhap a %d",i);
//		scanf("%d",&a[i]);
//	}

for(int i = 0; i<n; i++)
    {
        printf("phan tu %d = ",i);
        scanf("%d",&A[i]);
    }
}
int TongMang(int a[],int n){
	int s=0;
	for(int i=1; 1<=n; i++){
		s+=a[i];
	}
	return s;
}
main(){
	int a[100],n;
	printf("Nhap so phan tu trong mang: ");
	scanf("%d",&n);
	Nhap(a, n);
	TongMang( a, n);
}
