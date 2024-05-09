#include <stdio.h>
#include <stdlib.h>

int mdc(int a,int b){
    if(b==0){
     return a;

    }else if(a==b){
        return a;

    }else {
        int resposta = mdc(b,a%b);
        return resposta;
    }
  }

  /*
  int mdc(int a,int b){
    if(b==0){
     return a;

    }else if(a==b){
        return a;
    }else if(a>b){
        int resposta = mdc(a - b,b);
        return resposta;
    }else {
        return mdc(b,a);
    }
  }
  */
int main(){
    int x,y;
    printf("Digite dois numeros inteiros: ");
    scanf("%d%d",&x,&y);
    printf("Resultado: %d",mdc(x,y));

return 0;
}
