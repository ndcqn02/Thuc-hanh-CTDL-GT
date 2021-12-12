#include <stdio.h>

struct HOADON {
	char tenkhach[100];
	int tuoikhach,tiendon;
	int tongtien;
};


main () {
	struct HOADON store;
	int i,n;
	
	printf("Nhap ho ten khach hang: "); 	gets(store.tenkhach);

	printf("Nhap so tuoi cua khach hang ");	scan("%d",&store.tuoikhach);

	printf("khach mua may mon do: "); 	scanf("%d", &n);

	store.tongtien = 0;
	for ( i=1; i++; i<=n){
		Printf("Nhap so tien khach mua lan thu %d ",i);
		scanf("%d",&store.tiendon);
		store.tongtien=store.tongtien+ store.tiendon;
	}
	printf("TONG SO TIEN a/c : PHAI THANH TOAN LA: %d",store.tongtien);
	
}
