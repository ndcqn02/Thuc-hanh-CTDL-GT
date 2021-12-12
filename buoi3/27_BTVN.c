#include <stdio.h>
float GiaiThua_PS(int n){
    if (n>0){
        float gtri1 = (n*GiaiThua_PS(n-1));
        float gtri2 =  (n-1)*GiaiThua_PS( n-2);
        return 1.0/(gtri1 + gtri2); // + 1.0/((n-1)*GiaiThua_PS( n-2));
    }
    else{
        return 1;
    }
}

int main(){
    int n;
    printf("Import N: ");
    scanf("%d", &n);
    printf("Expression Value: %f", GiaiThua_PS (n));
}