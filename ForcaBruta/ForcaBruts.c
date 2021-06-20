#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char alfabeto[] =
"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%¨&*()_+{}?:^`´[]~";
static const char senha[] = "Lu";


static const int alfabetoTam = sizeof(alfabeto) - 1;

void implementacaoBruta(char* stringFinal, int index, int maxTam) // função recursiva para implementação da string
{
    for (int i = 0; i < alfabetoTam; ++i)
    {
        stringFinal[index] = alfabeto[i];

        if(strcmp(stringFinal, senha) == 0) // Comparação de strings
        {
            printf("Encontrado: %s\n", stringFinal);
            exit(0);
        }

        if (index == maxTam - 1){
            printf("%s\n", stringFinal);
        }
        else implementacaoBruta(stringFinal, index + 1, maxTam);
    }
}

void sequenciaBruta(int tamLimite)
{
    char* ult = malloc(tamLimite + 1);

    for (int i = 1; i <= tamLimite; ++i)
    {
        memset(ult, 0, tamLimite + 1); //remover ultimos caracteres antes de rodar a função novamente
        implementacaoBruta(ult, 0, i);
    }

    free(ult);
}

int main(void)
{
    sequenciaBruta(2); //definir tamanho máximo de combinações
    return 0;
}