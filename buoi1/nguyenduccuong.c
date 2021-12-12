#include <conio.h>
#include <stdio.h>
#include <math.h>

main() 
{
	float  s,dl,db,h;
	float  stron,pi,r;
	float  stg,cc,cd;
	
//	dien tich hinh thang
	printf("Nhap do dai  lan luot:  Day lon:=\tDay be:=\tChieu cao:=\t");
	scanf("%f%f%f",&dl,&db,&h);
	s=(dl+db)*h/2;
	printf("Dien tich hinh thang la:= %f \n",s);
	
// dien tich hinh tron
	printf("Nhap do dai ban kinh R:= \n");
	scanf("%f",&r);
	pi=3.14;
	stron=pi*r*r;
	printf("Dien tich hinh tron la:= %f \n",stron);

// Dien tich hinh tam giac
	printf("Nhap do dai lan luot chieu cao, canh day")	;
	scanf("%f%f",&cc,&cd);
	stg= (cc*cd)/2;
	printf("Dien tich tam giac la:= %f",stg);
	getch ();
}
