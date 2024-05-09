#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void substituirEspacos(char *mensagem)
{
    int i;
    for (i = 0; i < strlen(mensagem); i++)
    {
        if (mensagem[i] == '#')
        {
            mensagem[i] = ' ';
        }
    }
}

void cifraDeCesar(char *mensagem)
{
    int i;

    //percorre toda a string
    for (i = 0; i < strlen(mensagem); i++)
    {
        //quando encontra um caractere do alfabeto, minusculo ou maiusculo
        if (((int)mensagem[i] >= 65 && (int)mensagem[i] <= 90) || ((int)mensagem[i] >= 97 && (int)mensagem[i] <= 122))
        {
            if (((int)mensagem[i] - 5 > 64 && (int)mensagem[i] < 91) || (int)mensagem[i] - 5 > 96)
            {
                //caso durante a conversão a letra atinja um valor fora do alfabeto o caracter "volta" para o começo do alfabeto
                mensagem[i] = (char)((int)mensagem[i] - 5);
            }
            else
            {
                //caso contrário ele segue o protocolo de cifração
                mensagem[i] = (char)((int)mensagem[i] - 5 + 26);
            }
        }
    }
}

void refletirBloco(char *mensagem)
{
    int tamMensagem = strlen(mensagem);
    int i;
    char aux;

    // reflete o bloco (separado a cada 2 elementos e avança 2 casa pra modificar os proximos 2
    for (i = 0; i <= tamMensagem; i += 2)
    {
        aux = mensagem[i];
        mensagem[i] = mensagem[i + 1];
        mensagem[i + 1] = aux;
        // printf("i: %d",i);
    }
    // printf("\n");
}

void permutarBlocos(char *mensagem)
{

    int i, j = 0;
    int tamMensagem = strlen(mensagem);
    // if((tamMensagem/2)%2==0){
    //     tamMensagem--;
    // }
    char aux;
    // printf("%ld\n",strlen(mensagem));

    // permuta os blocos
    for (i = 0, j = 0; i < tamMensagem / 2; i += 2)
    {
        if (j % 2 == 0)
        {
            //permuta o primeiro elemento de cada bloco
            aux = mensagem[i];
            mensagem[i] = mensagem[tamMensagem - i - 2];
            mensagem[tamMensagem - i - 2] = aux;

            //permuta o segundo elemento de cada bloco
            aux = mensagem[i + 1];
            mensagem[i + 1] = mensagem[tamMensagem - i - 1];
            mensagem[tamMensagem - i - 1] = aux;

            // printf("%d --", j);
        }
        j++;
    }
    // printf("\n");
}

int bin2dec(int num)
{
    int decimal = 0, base = 1, rem;
    // printf("num: %d\n",num);
    while (num > 0)
    {
        rem = num % 10; /* divide the binary number by 10 and store the remainder in rem variable. */
        decimal = decimal + rem * base;
        num = num / 10; // divide the number with quotient
        base = base * 2;
    }
    // printf("b2d : %d\n", decimal);
    return decimal;
}

void retirarFalsoChar(char *mensagem, int falsoCharPos)
{
    int i;
    int tam = strlen(mensagem);
    // printf("tamMensagm: %d\n mensagem: %s\n falsoCharPos: %d\n",tam, mensagem, falsoCharPos);

    for (i = (falsoCharPos - 1); i <= (tam - 1); i++)
    {
        mensagem[i] = mensagem[i + 1];
    }
    // printf("mensagem sem falso char: %s\n",mensagem);
}
void retirarEspacoInicial(char *mensagem)
{
    // printf("strlen: %ld\n",strlen(mensagem));
    if (mensagem[strlen(mensagem)-1] == ' ')
    {
        mensagem[strlen(mensagem)-1] = '\0';
    }
}
int main()
{
    FILE *arquivo;
    int falsoCharPos;
    char nome_arq[20];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arq);

    arquivo = fopen(nome_arq, "r");
    if (arquivo == NULL)
    {
        fprintf(stderr, "Erro ao tentar abrir arquivo.txt.");
        return 1;
    }

    /* Pula até o fim do arquivo -5 posicoes para quantificar o tamanho da mensagem */
    fseek(arquivo, -5, SEEK_END);

    /* Lê o indicador de posição (em bytes) */
    long tamanho = ftell(arquivo); // numero de caracteres da mensagem
    fseek(arquivo, 0, SEEK_SET);   //coloca o cursor na posicao inicial
    // printf("O arquivo.txt possui %ld bytes.\n", tamanho);

    char mensagem[100000];

    fscanf(arquivo, "%d", &falsoCharPos); // numero do falso caracter, em binario

    fseek(arquivo, 0, SEEK_SET); //coloca o cursor na posicao inicial
    char  mensagemFalsoChar[tamanho+5];
    mensagemFalsoChar[tamanho+5] = '\0';
    fread(mensagemFalsoChar, tamanho + 5, 1, arquivo);

    fseek(arquivo, 5, SEEK_SET);

    fread(mensagem, tamanho, 1, arquivo); // o resto do arquivo eh a mensagem, portanto ela eh passada para a variavel criada
    fclose(arquivo);                      //fecha o arquivo
    // printf("tamanho: %ld   ::   strlen: %ld\n", tamanho, strlen(mensagem));
    printf("\n--------------------\nMensagem codificada:\n--------------------\n%s\n", mensagemFalsoChar);

    // printf("mensagem: %s\n", mensagem);
    // printf("%d\n",falsoCharPos);
    falsoCharPos = bin2dec(falsoCharPos); // c onverte o numero binario em decimal
    // printf("%d\n",falsoCharPos);

    retirarFalsoChar(mensagem, falsoCharPos); //retira o caracter falso da mensage
    // printf("falso:   %s\n", mensagem);

    mensagem[strlen(mensagem) - 1] = '\0'; // setando o final da nova mensagem, se m o char falso
    // printf("%s\n",mensagem);

    refletirBloco(mensagem);        //printf("refletir  %s\n", mensagem);
    permutarBlocos(mensagem);       //printf("permutar  %s\n", mensagem);
    substituirEspacos(mensagem);    //printf("espaco    %s\n", mensagem);
    retirarEspacoInicial(mensagem); //printf("reti      %s\n", mensagem);
    cifraDeCesar(mensagem);         //printf("cesar     %s\n", mensagem);

    printf("----------------------\nMensagem decodificada:\n----------------------\n%s",mensagem);

    return 0;
}


// Digite o nome do arquivo:
// --------------------
// Mensagem codificada:
// --------------------
// 01111tinhkn#ftyH#y#Xwfxfitufjxmsfk#jrqjzjytrhjr#fwfiknxji#v#sjx#nhjy#w#f#jsju#t#xjcjjih#wkfw#F

// ----------------------
// Mensagem decodificada:
// ----------------------
// A cifra de Cesar pode ser facilmente decifrada mesmo que se tenha apenas o texto cifrado

// 01111tinhkn#ftyH#y#Xwfxfitufjxmsfk#jrqjzjytrhjr#fwfiknxji#v#sjx#nhjy#w#f#jsju#t#xjcjjih#wkfw#F

// Digite o nome do arquivo:
// --------------------
// Mensagem codificada:
// --------------------
// 01111tinhkn#ftyH#y#Xwfxfitufjxmsfk#jrtinhkn#ftyH#y#Xwfxfitufjxmsfk#jrqjzjytrhjr#fwfiknxji#v#sjx#nhjy#w#f#jsju#t#xjcjjih#wkfw#F

// ----------------------
// Mensagem decodificada:
// ----------------------
// A cifra de Cesar pode ser facilmente decifrada mesmo que se tenha apenas o texto cifrado
