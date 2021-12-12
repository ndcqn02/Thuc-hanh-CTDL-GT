#include <stdio.h>

int i;
void Nhap(int a[], int n){
	for(i=1; i<=n; i++){
		printf("Nhap gia tri thu %d: ",i);
		scanf("%d",&a[i]);
	}
}
void In(int a[], int n){
	printf("Cac phan tu trong mang gom: ")
	for(i=1; i<=n; i++){
		printf("%d ",a[i]);
	}
}
//bai 34 dem so nguyen duong(positive) ,am(negative) 
int Count_positive(int a[],int n){
	int positive=0;
	for(i=1; i<=n; i++){
		if(a[i]>0)
			positive+=1;
	}
	return positive;
}
int Count_negative(int a[],int n){
	int negative=0,am=0;
	for(i=1; i<=n; i++){
		if(a[i]<0)
			negative+=1;
	}
	return negative;
} 

//bai 35 tinh tong cac so chan(even) trong day
int Sum_even(int a[],int n){
	int even=0;
	for(i=1; i<=n; i++){
		if(a[i]%2==0)
			even+=a[i];
	}
	return even;
}
//bai 36 tinh tong cac so le(odd) trong day
int Sum_odd(int a[],int n){
	int odd=0;
	for(i=1; i<=n; i++){
		if(a[i]%2 != 0)
			odd+=a[i];
	}
	return odd;
}
//bai 37 tong cac so am
int Sum_negative(int a[],int n){
	int negative=0;
	for(i=1; i<=n; i++){
		if(a[i]< 0)
			negative+=a[i];
	}
	return negative;
}
// bai 38 tong cac so duong
int Sum_positive(int a[],int n){
	int positive=0;
	for(i=1; i<=n; i++){
		if(a[i] > 0)
			positive+=a[i];
	}
	return positive;
}
// bai 39 tinh tong cac so chia het cho 5
int Sum_divide5(int a[], int n){
	int sum=0;
	for(i=1; i<=n; i++){
		if (a[i]%5==0)
			sum+=a[i];
	}
	return sum;
}
// bai 40 find max in number sequence
int Number_max(int a[], int n){
	int max=a[1];
	for(i=2; i<=n; i++){
		if (a[i]>max)
			max=a[i];
	}
	return max;
}
//bai 41 find min in number sequence
int Number_min(int a[], int n){
	int min=a[1];
	for(i=2; i<=n; i++){
		if (a[i] < min)
			min=a[i];
	}
	return min;
}
//bai 42 find even number max in number sequence
int Number_evenmax(int a[], int n){
	int maxEven;
	for(i=2; i<=n; i++){
		if (a[i]%2==0)
			if(a[i]>maxEven)
				maxEven=a[i];
	}
	return maxEven;
}
//bai 43 find positive number min in number sequence
int Number_posiMin(int a[], int n){
	int minposi;
	for(i=2; i<=n; i++){
		if (a[i]%2!=0)
			if(a[i]< minposi)
				minposi=a[i];
	}
	return minposi;
}
main(){
	int n,*ds;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	ds = new int[n+1];
	Nhap(ds, n);
	In(ds, n);
	printf("\n(bai 34) Trong day co %d so am  ",Count_negative(ds,n));
	printf("\n(bai 35) Trong day co %d so duong ",Count_positive(ds, n));
	printf("\n(bai 36) Tong cac so chan trong day la: %d",Sum_even(ds,n));
	printf("\n(bai 37) Tong cac so le trong day la : %d",Sum_odd(ds, n));
	printf("\n(bai 38) Tong cac so duong trong day la: %d",Sum_positive(ds, n));
	printf("\n(bai 39) Tong cac so chia het cho 5 la: %d",Sum_divide5(ds,  n));
	printf("\n(bai 40) So lon nhat trong day la: %d",Number_max(ds,  n));
	printf("\n(bai 41) So nho nhat trong day la: %d",Number_min(ds,  n));
	printf("\n(bai 42) So lon nhat trong cac so chan la: %d",Number_evenmax(ds,  n));
	printf("\n(bai 43) So nho nhat trong cac so le: %d",Number_posiMin(ds, n));
}
