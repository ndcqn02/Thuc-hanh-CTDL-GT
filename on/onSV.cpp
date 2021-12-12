#include <stdio.h>
#include <string.h>
struct SinhVien{
	char ten[10];
	char masv[10];
	float dtb ;
};

void nhap(SinhVien sv[], int n ){
	for(int i=1; i<=n ; i++){
		fflush(stdin);
		printf("Nhap ma sv %d: ",i);
		gets(sv[i].masv);
		printf("ten sinh vien : ");
		gets(sv[i].ten);	
		printf("diem trung binh: ");
		scanf("%f",&sv[i].dtb);	
	}
}

void in(SinhVien sv[], int n){
	printf("\n%19s| %10s| %f", "masv", "ten" , "dtb");		
	for(int i=1; i<= n ; i++){
		printf("\n%20s| %10s| %f", sv[i].masv, sv[i].ten , sv[i].dtb);		
	}
}

int timKiem(SinhVien sv[] , int n, char tk[]){
	for( int i=1; i<=n; i++){
		if( strcmp(sv[i].masv,tk)==0)
			return i;
	}
	return 0;
}

void chen(SinhVien sv[], int n, )
main(){
	int n;
	SinhVien *sv;
	char tim[50];
	printf(" Nhap so phan tu: ");
	scanf("%d",&n);
	sv = new SinhVien[n+1];
	nhap(sv,  n );
	in(sv,  n );
	printf(" Nhap ma sinh vin muon tim kiem : ");
	scanf("%s",&tim);
	if (timKiem(sv,n ,tim)!=0)
		printf(" co trong danh sach");
	else
		printf(" khong co trong ds ");
}
