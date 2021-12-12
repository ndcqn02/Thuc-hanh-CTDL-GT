#include <stdio.h>
int i;
void Nhap(int a[], int n){
	for(i=1; i<=n; i++){
		printf("Nhap gia tri thu %d: ",i);
		scanf("%d",&a[i]);
	}
}
void In(int a[], int n){
	printf("Cac phan tu trong mang gom: ");
	for(i=1; i<=n; i++){
		printf("%d ",a[i]);
	}
}


void ChenBietVt(int a[], int n, int so, int vt){
	if(vt>n)
		vt=n+1;
	if(vt<1)
		vt=1;
	for(i=n+1; i>=vt; i--){
		a[i]=a[i-1];	
	}
	a[vt]=so;
	n++;
	In(a,n);
}

main(){
	int n,*ds,so,vt;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	ds = new int[n+1];	
	Nhap(ds, n);
	In(ds, n);
	printf("\n(bai 6) Nhap so  va vi tri muon chen: ");
	scanf("%d%d",&so,&vt);
	ChenBietVt(ds, n, so,vt);
	
}
