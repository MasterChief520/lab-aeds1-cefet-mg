#include <stdio.h>
#include <stdlib.h>

void dec2bin(int dec){
    if (dec == 0 || dec ==1){
        printf("%d",dec);
    }else {
        dec2bin(dec/2);
        printf("%d",dec%2);
    }
}
int main(){
    int x;
    printf("Digite um numero inteiro: ");

    scanf("%d",&x);

    printf("Resultado: ");

    dec2bin(x);

return 0;
}
