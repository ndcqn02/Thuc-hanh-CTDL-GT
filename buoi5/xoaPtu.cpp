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
		if(a[i]==so)
			return i;
	}
}

void XoaPT(int a[], int n, int so){
	int vt=ViTri(a, n,so);
	printf("vi tri la: %d",vt);
	for(i=vt; i<=n;i++){s
		a[i]=a[i+1];	
	}
	n--;
	In(a,n);
}

main(){
	int n,*ds,so;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	ds = new int[n+1];	
	Nhap(ds, n);
	In(ds, n);
	printf("\n(bai 8) Nhap so muon xoa: ");
	scanf("%d",&so);
	XoaPT(ds,  n,  so);
	
}
