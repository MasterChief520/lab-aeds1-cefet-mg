#include <stdio.h>
#include <stdlib.h>

int mult(int base,int exp){
    if (exp == 1){
        return base;
    }else if(exp == 0){
        return 1;
    }else{
        int resultado = base* mult(base, exp - 1);
        return resultado;
    }
  }
int main(){
    int x,y;
    printf("Digite dois numeros inteiros: ");
    scanf("%d%d",&x,&y);
    printf("Resultado: %d",mult(x,y));

return 0;
}
