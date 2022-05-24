#include <stdio.h>
 int  i;
 
void in(int a[], int n){
for(i =1; i<=n ; i++){
	printf("%d ",a[i]);
 }
}
 
void hoanVi(int &x, int &y){
	int tg;
		tg = x;
		x = y;
		y = tg;
}


void SXchon(int a[], int n){
	int min,j;
	for(i=1; i<=n -1; i++){
		min =i;
		for(j=i+1; j<= n;j++){
			if(a[j] < a[min]){
				min = j;
				hoanVi(a[i], a[min]);
			}
		}
	}
}
 
 

void SXchen(int a[], int n){
	int j;
	for(i =2; i<=n; i++){
		j = i;
		while(j >0  && a[j-1] > a[i]){
			a[j] = a[j-1];
			j --;
		}
		a[j] = a[i];
	}
}

void sepXep_noiBot(int a[], int n){
	int t, d,tg;
	for(t =1; t<=n-1 ; t++){
		for(d =n; d>=t+1; d--){
			if(a[d]< a[d-1])
				hoanVi(a[d], a[d-1]);
		}
 	}
}



void insertionSort(int a[], int n){
	int index, value;
	for (int i = 2; i < n+1; i++){
		index = i;
		value = a[i];
		while (index > 1 && a[index - 1] > value){
			a[index] = a[index - 1];
			index --;
		}
		a[index] = value;
	}
}
 
 main(){
 	int a[100];
 	int n;
 	printf(" so phan tu : ");
 	scanf("%d",&n);
 	for(i =1; i<=n ; i++){
 		printf(" phan tu %d : ",i);
 		scanf("%d",&a[i]);
	 }
	in(a, n);
//	printf("Sap xep noi bot :  ");
	//sepXep_noiBot(a, n);
//	in(a,  n);
//	printf(" \n Sap xep chon :  ");
//	SXchon(a,  n);
//	in(a,  n);
	printf("\n Sap xep  chen : ");
	insertionSort(a,  n);
	in(a,  n);
 }
