#include <stdio.h>
#include <math.h>
//bai 25
float TongPS_ChanTru(int n){
        if(n==1)
            return 1;
        if(n%2==0)
            return  -1.0/n + TongPS_ChanTru(n-1);
        else 
            return  1.0/n + TongPS_ChanTru(n-1);
    }
//bai 26
float TongXenKePS_LeTru(int n){
    if (n==1)
        return -1;
    if(n%2!= 0)
        return  (-1.0/n + TongXenKePS_LeTru(n-1));
    else
        return  (1.0/n + TongXenKePS_LeTru(n-1));
}
//bai 27 
int GiaiThua(int n){
        if(n>0)
            return n* GiaiThua(n-1);
        else 
            return 1;           
    }
//bai 28
float TongPS_GiaiThua (int n){
	if(n==1)
		return 1;
	else
		return 1.0/GiaiThua(n) + TongPS_GiaiThua (n-1);
}
//bai 29
float Tong1Phan_GT_LeCong(int n){
	if(n==1)
		return 1;
	else
		return 1.0/(pow(-1,(n+1))*GiaiThua(n) )+ Tong1Phan_GT_LeCong(n-1);
}
//bai 30
float Tong1Phan_GT_LeTru(int n){
	if(n==1)
		return -1;
	else
		return -1.0/(pow(-1,(n+1))*GiaiThua(n) )+ Tong1Phan_GT_LeTru(n-1);
}
main(){
	int n, nn,so,n28,n29,n30;
/*	printf("(bai 25)Nhap so  n: ");
	scanf("%d",&n);
	printf(" Tong la %f\n",TongPS_ChanTru(n));
	printf("(bai 26)Nhap so  N: ");
	scanf("%d",&nn);
	printf(" Tong la %f\n",TongXenKePS_LeTru(nn));*/
	printf("(bai 27) Nhap so :");
	scanf("%d",&so);  
	printf(" Giai thua %d\n",GiaiThua(so));/*
	printf("(bai 28)Nhap gia tri N: ");  
	scanf("%d",&n28);
	printf("Tong la %f \n",TongPS_GiaiThua ( n28)); */
	printf("(bai 29)Nhap gia tri N: ");
	scanf("%d",&n29);
	printf("Tong la %f\n",Tong1Phan_GT_LeCong(n29));
	printf("(bai 30)Nhap gia tri N: ");
	scanf("%d",&n30);
	printf("Tong la %f",Tong1Phan_GT_LeTru(n30));
	
}
