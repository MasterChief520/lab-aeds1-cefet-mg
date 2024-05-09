#include <stdio.h>
#include <stdlib.h>

int maximo (int n, int v[])
{
   if (n == 1)
      return v[0];
   else {
      int x;
      x = maximo (n-1, v);
      /* x é o máximo de v[0..n-2]*/
      if (x > v[n-1]) return x;
      else return v[n-1];
   }
}
void Algoritmo(int A[], int n){
    int i, j, aux;
    for (j=0; j<n;j++){
        for(i=0;i<n-1;i++){
            if(A[i]>A[i+1]){
                aux = A[i];
                A[i] = A[i+1];
                A[i+1]= aux;
            }
        }
    }
}
int main(){
    int n,max,i;

    int v[10]={3,5,1,4,10,7,9,8,15,13};
    for(i=0;i<10;i++){
        printf("Posicoes[%d] = %d\n",i,v[i]);
    }
    n = 10;
    printf("\n");
    max = maximo (n,v);
    printf("Maximo: %d",max);
    printf("\n");
    Algoritmo(v,n);
    for(i=0;i<10;i++){
        printf("Posicoes[%d] = %d\n",i,v[i]);
    }
    printf("\n");
return 0;
}
