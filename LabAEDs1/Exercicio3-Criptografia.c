#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* removerLIXO(char*mensagem, int decimal){
    int i=0;
    for(i ;i<5 ;i++){
        mensagem[i]=' ';
    }
  mensagem[decimal+4] = ' ';

return mensagem;
}

char* copiar(char mensagem[], int tam){
    int j=0;
    int i=0;
    for(i;i<tam;i++){
        if(mensagem[i] != ' '){
            mensagem[j]=mensagem[i];
            j++;
        }
    }
return mensagem;
}


char* troca(int tamanho, char mensagem2[]){
    int tam = tamanho;
    tamanho = (tamanho/2) -1;
    int i=0;
    for (i;i<tamanho;i++){
        char aux = mensagem2[i];
        char aux2 = mensagem2[i+1];
        mensagem2[i] = mensagem2[tam-4];
        mensagem2[tam-4] = aux;
        mensagem2[i+1] = mensagem2[tam-3];
        mensagem2[tam-3]= aux2;
        i+=3;
        tam -=4;
    }
    return mensagem2;
}

char* inverte(int t, char mensagem[], char mensagem2[]){
    int i=0;
    int tam = t;
    for(i; i< tam; i++){
    mensagem2[i] = mensagem[i+1];
    mensagem2[i+1] = mensagem[i];
    i++;
    }
return mensagem2;
}

char* decodifica(int tam, char mensagem3[],char decodificado[]){
    int i =0;
    for (i; i<=tam;i++){
    if (mensagem3[i] =='#'){
    decodificado[i]=32;
    }else if ((mensagem3[i] >97)|| (mensagem3[i] <123)){
    decodificado[i] = mensagem3[i]-5;
    }else if((mensagem3[i]>65) || (mensagem3[i] <91)){
    decodificado[i] = mensagem3[i]-5;
    }
    if(mensagem3[i]==97){
    decodificado[i]= 118;
    }
    if(mensagem3[i]==98){
    decodificado[i]= 119;
    }
    if(mensagem3[i]==99){
    decodificado[i]= 120;
    }
    if(mensagem3[i]==100){
    decodificado[i]= 121;
    }
    if(mensagem3[i]==101){
    decodificado[i]= 122;
    }
    if(mensagem3[i]==65){
    decodificado[i]= 86;
    }
    if(mensagem3[i]==66){
    decodificado[i]= 87;
    }
    if(mensagem3[i]==67){
    decodificado[i]=88 ;
    }
    if(mensagem3[i]==68){
    decodificado[i]= 89;
    }
    if(mensagem3[i]==69){
    decodificado[i]= 90;
    }

    }
}
int binParaDec(int x){
     int dec=0,base=1,resto;
    while (x > 0){
        resto=x% 10;
        dec=dec+resto*base;
        x=x/10;
        base=base*2;
    }
    return dec;
}

int main(){
    int i;
    char nome[35];

    printf ("Digite o nome do arquivo: ");
    scanf("%s", nome);

    FILE *arquivo;
    arquivo = fopen (nome, "r");

    if(arquivo == NULL){ /*verificar se consegue ler o arquivo*/
    printf ("Esse arquivo nao pode ser lido. \n");
    exit(0);
    }
    char mensagem[25000];
    int tam = 0;
    tam = sizeof(mensagem);

    for (i = 0; i<tam; i++ ){
        mensagem[i] = ' ';
    }

    char *result = fgets(mensagem, 25000,arquivo);
    if(result == NULL)
    printf("Erro na leitura \n");

    else
    fclose(arquivo);

    int letrasdamensagem =0;

    for(i = 0; i<tam;i++){
        if((mensagem[i] == '\n')||(mensagem[i] ==' ')){
            letrasdamensagem++;
        }
    }
    tam = tam - letrasdamensagem;

    if(tam%2==0){}
    else{
        tam +=1;
    mensagem[tam]= '#';
    }
printf("\n--------------------\nMensagem codificada:\n--------------------\n%s\n", mensagem);

    int binario = 0 ;
    binario += mensagem[4]-'0';
    binario += (mensagem[3]-'0')*10;
    binario += (mensagem[2]-'0')*100;
    binario += (mensagem[1]-'0')*1000;
    binario += (mensagem[0]-'0')*10000;
    int decimal=0;
    decimal = binParaDec(binario);

    removerLIXO(mensagem,decimal);
    char mensagem2[tam];
    copiar(mensagem,tam);
    char mensagem3[tam];
    troca(tam-6, mensagem);
    inverte(tam,mensagem,mensagem2);
    char decodificado[tam-6];
    decodifica(tam,mensagem2, decodificado);
    decodificado[tam-8] = '\0';


printf("----------------------\nMensagem decodificada:\n----------------------\n%s", decodificado);

    return 0;
}

