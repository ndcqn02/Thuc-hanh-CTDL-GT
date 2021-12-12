#include <stdio.h>
#include <math.h>
//bai 2 tinh dien tich hinh tron dung ham
 float pi=3.14;
 float DT_HINHTRON(float r){
 	float stron;
 	stron= pi*r*r;
 	return stron;
 }
 main(){
 	float r;
 	printf("Nhap do dai cua ban kinh:  ");
	scanf("%f",&r);
	printf("Dien tich cua hinh tron la: %f \n",DT_HINHTRON( r));
 }

