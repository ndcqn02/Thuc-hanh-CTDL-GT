#include <stdio.h>

typedef struct SINHVIEN {
	char  ht[25],lop[10];
	float dtb;
}

main() {
	SINHVIEN; sv;
	printf("hoten");// gets (sv.ht);
	printf("lop ");  //gets (sv.lop);
	printf("diem trun gbinh");// scanf("%f",& sv.dtb);
//	printf("print all:  ",sv.ht, sv.lop, sv.dtb);
}
