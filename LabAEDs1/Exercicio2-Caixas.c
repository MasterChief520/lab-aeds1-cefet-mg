#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    FILE *arquivo;
    arquivo = fopen("jogocaixas.txt","w");
    fprintf(arquivo," a ");
    fclose(arquivo);


return 0;
}
