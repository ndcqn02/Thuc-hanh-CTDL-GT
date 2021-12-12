#include <stdio.h>
int i;
void Nhap(int a[], int n){
	for(i=1; i<=n; i++){
		printf("Nhap gia tri thu %d: ",i);
		scanf("%d",&a[i]);
	}
}
void In(int a[], int n){
	for(i=1; i<=n; i++){
		printf("%d ",a[i]);
	}
}

int TimKiem(int a[], int n, int so){
	for(i=1; i<=n;i++){
		if( so==a[i]){
			return i;
		}
	}
	return 0;
}
void ChenBietVT(int a[], int &n, int vt, int chen){
	if(vt<=0)
		vt=1;
	if(vt>n)
		vt=n+1;
	for(i=n;i>=vt; i--)
		a[i+1]= a[i];
	a[vt]=chen;
	n++;
}

void Xoa(int a[], int &n, int xoa){
	int vt=TimKiem(a, n, xoa);
	for(i=vt;i<=n;i++){
		a[i]=a[i+1];
	}
	n--;
}
void SapXep(int a[], int &n){
	int j,tg;
	for(i=1; i<=n-1; i++){
		for(j=i+1; j<=n;j++){
			if(a[i]>a[j])
			{
				tg=a[i];
				a[i]=a[j];
				a[j]= tg;
			}
		}
	}
}
int TimKiemDayDaSX(int a[], int &n, int chen){
	for(i=1; i<=n;i++){ 
		if( chen<a[i])
			return i;
	}
	return 0;
}
void ChenDsDaSX(int a[], int &n, int chen){
	int vt = TimKiemDayDaSX(a, n,chen);
	for(i=n;i>=vt; i--)
		a[i+1]= a[i];
	a[vt]=chen;
	n++;
}

main(){
	int n,*ds,so,tim,chen,vt,xoa,chensx,tim5;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	ds = new int[n+1];	
	Nhap(ds, n);
	In(ds, n);
	printf("\n(bai 1) Nhap so muon tim: ");
	scanf("%d",&tim);
	if(TimKiem(ds,n,tim)!=0)
		printf("Co ");
	else
		printf("Khong co");
	printf("\n(bai2) Nhap so va vi tri muon chen: ");
	scanf("%d%d",&chen,&vt);
	ChenBietVT(ds, n, vt, chen);
	In(ds, n);
	printf("\n(bai 4) Nhap so muon xoa: ");
	scanf("%d",&xoa);
	Xoa(ds, n, xoa);
	In(ds, n);
	printf("\n(bai 5)Nhap so muon tim: ");
	scanf("%d",&tim5);
	if(TimKiem(ds,n,tim)!=0)
		printf("Co");
	else
		printf("Khong co");
	//
	printf("\nSap xep lai ds theo tang dan: ");
	SapXep(ds, n);
	In(ds, n);
	printf("\n(bai 7) Nhap so muon chen, cho ds da sap xep: ");
	scanf("%d",&chensx);
	ChenDsDaSX(ds, n, chensx);
	In(ds, n);
}
