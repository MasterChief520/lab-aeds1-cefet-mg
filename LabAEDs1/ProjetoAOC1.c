#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int i,j=0,num;
    num = 8;

    for(num ;num <num+9 ;num++){
        for(i=2;i<num;i++){
            if(num%i!=0){
                printf("Numero nao eh primo: \n");
                num++;
            }else{
                j++;
            }
        }
    }

    Printf("Possui %d numeros primos no intervalo",j);


return 0;
}
