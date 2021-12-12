#include <stdio.h>
#include <math.h>
//bai 3 tinh dien tich tam giac khi biet cday va chcao dung ham
 float DT_TAMGIAC(float cd, float ccao){
 	float stg;
 	stg= cd*ccao/2;
 	return stg;
 }
 main(){
 	float cd, ccao;
 	printf("Nhap do dai canh day:  ");
	scanf("%f",&cd);
	printf("Nhap do dai chieu cao tam giac:  ");
	scanf("%f",&ccao);
	
	printf("Dien tich cua tam giac  la: %f \n", DT_HINHTHANG(dl, db, cc));
 }

