#include <stdio.h>
#include <math.h>
	float pi=3.14;
//bai 4
	float  DT_TAMGIAC (float *a, float *b, float *c){
		float p;
		p= (*a+*b+*c)/2;
		return (sqrt(p*(p - *a)*(p-*b)*(p-*c)));
	}

// bai5 a
	float CVI_HINHTRON(float *r){
		float cvi;
		cvi=2*pi**r;
		return cvi;
	}
//bai 5b
	float CHUKYCL(float l)	{
		float t,g=10;
		t= 2*pi*sqrt(l/g);
		return t;
	}
//bai6
	int TONGCACCSO(int so){
		int i,str,ch,sch,sdv,tso;
		str=so/100; 
		ch=so/10;	
		sch=ch%10;
		sdv=so%10;	
		tso=0;
		tso=str+sch+sdv;
		return (tso);		
	}
//bai7
	float Z(float a, float b){
		float tu,mau;
		tu=pow(a,3)-pow((a+b),1.0/4); 
		mau=a+2;
		return (tu/mau);
	}
//bai 8
	float T(float x, float y){
		float tu, mau;
		tu= x*x - pow((x+y),1.0/3);
		mau= x-y;
		return (tu/mau);
	}
//bai9
	float Tlog(float x, float y){
		return(	log(x+y)/log(5));
	}
//bai10
	float THETICH(float R){	
		return (4*pi*pow(R,3)/3);
	}
		
main() {
	float a,b,c,tg,r,ht,l,cky,a7,b7,z,t8,x8,y8,x9,y9,t9,R,v;
	int so,tso;
	//bai4
	printf("Nhap do dai 3 canh cua tam giac lan luot a b c: ");
	scanf("%f%f%f",&a,&b,&c);
	tg= DT_TAMGIAC (&a, &b,&c);
	printf("Dien tich tam giac la: %f \n", tg);
	//bai5
	printf("Nhap ban kinh hinh tron: ");
	scanf("%f",&r);
	ht= CVI_HINHTRON(&r);
	printf("Chu vi hinh tron la: %f \n",ht);
	//bai5b
	printf("Nhap chieu dai con lac don: ");
	scanf("%f",&l);
	cky= CHUKYCL(l) ;
	printf("Chu ky con lac la: %f\n",cky);
	//bai6
	printf("Nhap so nguyen co ba chu so: ");
	scanf("%d",&so);
	tso= TONGCACCSO(so);
	printf("Tong cua 3 chu so la: %d \n",tso);
	//bai7
	printf("(bai7) Nhap lan luot 2 so a va b: ");
	scanf("%f%f",&a7,&b7);
	z= Z(a7, b7);
	printf("Ket qua cua Z la : %f\n",z);
	//bai8
	printf("(bai 8) Nhap lan luot 2 so X va Y: ");
	scanf("%f%f",&x8,&y8);
	t8=T(x8, y8);
	printf("Ket qua cua T la : %f \n",t8);
	//bai9
	printf("(bai 9) Nhap hai so x va y :  ");
	scanf("%f%f",&x9,&y9);
	t9= Tlog(x9,y9);
	printf("Ket qua T bai 9 la : %f\n",t9);
	//bai10	
	printf("Nhap R bai 10: ");
	scanf("%f",&R);
	v=THETICH( R);
	printf("The tich hinh cau la: %f",v);
	
		
}
