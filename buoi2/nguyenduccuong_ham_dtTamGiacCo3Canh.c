#include <stdio.h>
#include <math.h>
// bai 4 tinh dien tich tam giac khi biet 3 canh dung ham
float  DT_TAMGIAC (float *a, float *b, float *c){
		float p;
		p= (*a+*b+*c)/2;
		return (sqrt(p*(p - *a)*(p-*b)*(p-*c)));
	}
	
main() {
	float a, b, c,tg;
	printf("Nhap do dai 3 canh cua tam giac lan luot a b c: ");
	scanf("%f%f%f",&a,&b,&c);
	tg= DT_TAMGIAC (&a, &b,&c);
	printf("Dien tich tam giac la: %f \n", tg);
	
}
