#include<stdio.h>
#include<math.h>
float pi=3.14;
int g=10;
int choose;	
// bai15 a
	float CVI_HINHTRON(float r){
		float cvi;
		return 2*pi*r;
	}
//bai 15b
	float CHUKYCL(float l)	{
		float t,g=10;
		return 2*pi*sqrt(l/g);
	}
//bai16
	int TONGCACCSO(int so){
		int i,str,ch,sch,sdv,tso;
		str=so/100; 
		ch=so/10;	
		sch=ch%10;
		sdv=so%10;	
		tso=0;
		return (str+sch+sdv);		
	}
//bai17
	float Z(float a, float b){
		float tu,mau;
		tu=pow(a,3)-pow((a+b),1.0/4); 
		mau=a+2;
		return (tu/mau);
	}
//bai 18
	float T(float x, float y){
		float tu, mau;
		tu= x*x - pow((x+y),1.0/3);
		mau= x-y;
		return (tu/mau);
	}
//bai19
	float Tlog(float x, float y){
		return(	log(x+y)/log(5));
	}
//bai20
	float THETICH(float R){	
		return (4*pi*pow(R,3)/3);
	}	
void XULYMENU(){
	scanf("%d",&choose);
	switch (choose){
		case 151: 	{
			float r;
			printf("-- Ban da chon tinh chu vi hinh tron ---\n");
			printf(" Nhap ban kinh r :");
			scanf("%f",&r);
			printf(" Chu vi hinh tron:= %f\n",CVI_HINHTRON(r));
			break;
		}
		case 152: 	{
			float l;
			printf("-- Ban da chon tinh chu ky con lac ---\n");
			printf(" Nhap chieu dai con lac :");
			scanf("%f",&l);
			printf(" Chu ky con lac la:= %f\n",CHUKYCL( l));
			break;
		}
		case 16: 	{
			int so;
			printf("-- Ban da chon tinh tong cac chu so cua mot so nguye co 3 chu so\n");
			printf(" Nhap so co 3 chu so : ");
			scanf("%d",&so);
			printf(" Tong 3 chu so la := %d\n",TONGCACCSO( so));
			break;
		}
		case 17: 	{
			float a,b;
			printf("-- Ban da chon tinh gia tri bieu thuc Z\n");
			printf(" Nhap lan luot a va b : ");
			scanf("%f%f", &a,&b);
			printf(" Tong 3 chu so la := %f\n",Z(a,  b));
			break;
		}
		case 18: 	{
			float x,y;
			printf("-- Ban da chon tinh gia tri bieu thuc T\n");
			printf(" Nhap lan luot x va y: ");
			scanf("%f%f",&x,&y);
			printf(" Tong 3 chu so la := %f\n",T(x,  y));
			break;
		}
		case 19: 	{
			float xx,yy;
			printf("-- Ban da chon tinh log T\n");
			printf(" Nhap lan luot x va y: ");
			scanf("%f%f",&xx,&yy);
			printf(" Tong 3 chu so la := %f\n",Tlog( xx,yy));
			break;
		}
		case 20: 	{
			float R;
			printf("-- Ban da chon tinh the tich hinh cau\n");
			printf(" Nhap ban kin R cua hinh cau: ");
			scanf("%f",&R);
			printf(" The tich hinh cau la := %f\n",THETICH( R));
			break;
		}
		default: {
			printf(" !!! Gia tri khong phu hop-Xin lai (151 152 16 17 18 19 20) \n");
						
		}

	}
}




main(){
	
	printf(" Chon 151 de tinh chu vi hinh tron\n");
	printf(" Chon 152 de tinh chu ky con lac don\n");
	printf(" Chon 16 de tinh tong cac chu so cua mot so nguye co 3 chu so\n");
	printf(" Chon 17 de tinh gia tri bieu thuc Z\n");
	printf(" Chon 18 de tinh gia tri bieu thuc T\n");
	printf(" Chon 19 de tinh log T \n");
	printf(" Chon 20 de tinh the tich hinh cau \n");
	printf(" Xin moi ban chon \n");
	printf("-------------------------------------------\n");
	
	do{
		
		XULYMENU();	
		printf(" =>Press Continue\n");
	}
	while(choose>0);
}


