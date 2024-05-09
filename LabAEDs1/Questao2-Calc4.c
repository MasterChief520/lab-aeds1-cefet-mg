#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    Thales Henrique Bastos Neves
    Questão 2-a) Fatorial 1-d))     */

double cosseno(int n){
        return cos(n)/(pow(3,n));
}
double soma(){
    double soma=0;
    int i,fim;
    for(i=1,fim=10;i<fim;i++){
        soma+=cosseno(i);
        printf("Iteracao: %d Resultado: %f\n",i,soma);
    }
    return soma;
}
int main(){
    float x;
    x=soma();
    printf("Resultado final: %f\n",x);

return 0;
}
