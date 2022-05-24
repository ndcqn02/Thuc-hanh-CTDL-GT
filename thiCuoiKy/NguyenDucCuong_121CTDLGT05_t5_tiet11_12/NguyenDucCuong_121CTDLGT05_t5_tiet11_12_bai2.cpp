#include <stdio.h>
#include <math.h>
void HoanVi(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void SapXepNoiBot(int a[], int n){	
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
		   if(a[j] < a[j-1])
		       HoanVi(a[j], a[j-1]);
}

void SapXepNoiBotTriTuyetDoi(int a[], int n){	
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
		   if(abs(a[j]) < abs(a[j-1]))
		       HoanVi(a[j], a[j-1]);
}
int DemMax(int a[], int n){
    int max = a[0];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    for (int  i = 0; i < n; i++)
    {
        if(a[i] == max)
            count++;
    }
    return count;
}

void IN(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int a[12]= {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    int n = 12;
    printf("DAY BAN DAU: ");
    IN(a, n);
    printf("\nSAP XEP TANG DAN: ");
    SapXepNoiBot (a, n);
    IN(a, n);
    printf("\nSAP XEP TANG DAN THEO TRI TUYET DOI : ");
    SapXepNoiBotTriTuyetDoi(a,  n);
    IN(a, n);
    printf("\nSo luong phan tu lon nhat trong day la : %d",DemMax(a,n)); 
}
