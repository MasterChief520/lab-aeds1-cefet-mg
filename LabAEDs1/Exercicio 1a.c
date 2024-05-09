#include <stdio.h>
#include <stdlib.h>

int Digitos(int N){
    if (N<10){
        return 1;
    }else{
        int cont = Digitos(N/10);
        return cont + 1;
    }
  }
int main(){
    int x;
    printf("Digite um numero inteiro: ");
    scanf("%d",&x);
    printf("Resultado: %d",Digitos(x));

return 0;
}
