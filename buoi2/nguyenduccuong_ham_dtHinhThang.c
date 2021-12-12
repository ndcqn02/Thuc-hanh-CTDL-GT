#include <stdio.h>
#include <math.h>
//bai 1tinh dien tich hinh thang dung ham
 float DT_HINHTHANG(float dl, float db, float cc){
 	float s;
 	s= (dl+db)*cc/2;
 	return s;
 }
 main(){
 	float dl, db, cc;
 	printf("Nhap do dai day lon:  ");
	scanf("%f",&dl);
	printf("Nhap do dai day be:  ");
	scanf("%f",&db);
	printf("Nhap do dai chieu cao:  ");
	scanf("%f",&cc);
	printf("Dien tich cua hinh thang la: %f \n", DT_HINHTHANG(dl, db, cc));
 }

