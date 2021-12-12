#include <stdio.h>
#include <string.h>
int i;
struct HOCSINH{
	char ten[50],msv[13];
	float toan,ly,hoa,dtb;
};
void Nhapsv(HOCSINH a[], int n){
	for(i=1; i<=n; i++){
		fflush(stdin);
		printf("Ten sv %d: ",i);
		gets(a[i].ten);
		printf(" Ma sinh vien: ");
		gets(a[i].msv);
		printf("Diem toan: ");
		scanf("%f",&a[i].toan);
		printf("Diem ly: ");
		scanf("%f",&a[i].ly);
		printf("Diem hoa: ");
		scanf("%f",&a[i].hoa);		
	}
}
void In(HOCSINH a[], int n){
		printf("\n%24s|%20s|%s","Ma SV","Ho ten","DiemTB");
	for(i=1; i<=n; i++){
		printf("\n%25s|%20s|%0.2f",a[i].ten,a[i].msv,a[i].dtb);
	}
}

void DiemTB(HOCSINH a[], int n){
	for(i=1; i<=n; i++){
		a[i].dtb= (a[i].toan + a[i].ly + a[i].hoa)/3;
	}
}

void InDTBHon5(HOCSINH a[], int n){
	int d=0;
	printf("/n");
	for(i=1; i<=n; i++){
		if(a[i].dtb>5){
			printf("\n%25s|%20s|%0.2f",a[i].ten,a[i].msv,a[i].dtb);
			d++;
		}
	}
	if(d==0)
		printf("Khong co hoc sinh nao co diem TB tren 5");
}
void SapXep(HOCSINH a[], int n){
	HOCSINH tg;
	int j;
	
	for(i=1; i<n; i++){
		for(i+1; j<=n;j++){
			if(a[i].dtb> a[j].dtb){
				tg=a[i];
				a[i]=a[j];
				a[j]= tg;
			}
		}
	}
}
main(){
	HOCSINH *ds;
	int n;
	printf("Nhap so hoc sinh: ");
	scanf("%d",&n);
	ds = new HOCSINH[n+1];
	Nhapsv(ds,  n);
//	In(ds,  n);
	DiemTB(ds,  n);
	In(ds,  n);
	printf("\n Diem trung binh hon 5 la: ");
	InDTBHon5(ds, n);
	SapXep(ds, n);
	printf("\nDay sau khi sap xep la: ");
	In(ds,  n);
	
}


















