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

int ViTri(int a[], int n, int so){
	for(i=1; i<=n; i++){
		if(a[i]>so)
			return i;
	}
}

void Chen(int a[], int n, int so){
	int vt=ViTri(a, n,so);
	for(i=n+1; i>=vt; i--){
		a[i]=a[i-1];	
	}
	a[vt]=so;
	n++;
	In(a,n);
}

main(){
	int n,*ds,so;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	ds = new int[n+1];	
	Nhap(ds, n);
	In(ds, n);
	printf("\n(bai 3) Nhap so muon chen: ");
	scanf("%d",&so);
	Chen( ds, n, so);
	
}
