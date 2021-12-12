//bai 31 tinh tong cac phan tu trong mang
#include <stdio.h>
void Nhap(int a[], int n){
for(int i = 1; i<=n; i++)
    {
        printf("phan tu %d = ",i);
        scanf("%d",&a[i]);
    }
}
int TongMang(int a[],int n){
	int s=0;
	for(int i=1; i<=n; i++){
		s+=a[i];
	}
	return s;
}
int KtraSoHoanThien(int so ){
	int t=0;
	for(int i=1; i<so; i++){
		if(so%i==0)
			t+=i;
	}
	if(t==so)
		return 1;
	else 
		return 0;
}
int DemSoHoanThien(int a[], int n){
	int d=0;
	for(int i=1; i<=n; i++){
		if(KtraSoHoanThien(a[i]) ==1)
			d++;
	}
	return d;
}
void DemChanLe(int a[], int n){
	int chan=0,le=0;
	for(int i=1; i<=n; i++){
		if(a[i]%2==0)
			chan++;
		else
			le++;
	}
	printf("Trong mang co %d so le\n",le);
	printf("Trong mang co %d so chan\n",chan);
}
main(){
	int a[100],n;
	printf("Nhap so phan tu trong mang: ");
	scanf("%d",&n);
	Nhap(a, n);
	printf("Tong cac phan tu la:  %d\n",TongMang( a, n));
	printf("Co %d so hoan thien trong day\n",DemSoHoanThien(a, n));
	DemChanLe(a, n);
}
