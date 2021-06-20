#include <stdio.h>
#include <stdlib.h>
#define TONELADAS 4

static int matriz[3][3] = {{1, 2, 31}, {2, 3, 47}, {3, 1, 14}};
static int melhoresSolucoes[3];

void imprimirMatriz()
{
    printf("Matriz:\n");
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            printf("\t|%i", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\t-----------\n\n");
}

void calcularSolucoes()
{
    int ciclo = 0;
    for (int i = 0; i <= 2; i++)
    {
        int item = matriz[i][0];
        int peso = matriz[i][1];
        int valor = matriz[i][2];

        printf("Item: %i, Peso: %i, Valor: R$%i\n", item, peso, valor);

        if(peso <= TONELADAS)
        {
            int quantidadePossivelDeCarregadas = TONELADAS/peso;
            int dinheiroRetornado = quantidadePossivelDeCarregadas * valor;
            printf("É possível carregar esse item em até %ix\nDinheiro retornado: R$%i\n", quantidadePossivelDeCarregadas, dinheiroRetornado);
            melhoresSolucoes[ciclo] = dinheiroRetornado;
            ciclo++;

            int possivelCarregarMaisPeso = 0;
            int quantidadePossivelQueSobrou = TONELADAS - (peso * quantidadePossivelDeCarregadas);

            VerificarSobras:
            printf("Sobrou espaço para carregar mais peso: ");
            if(quantidadePossivelQueSobrou > 0)
            {
                possivelCarregarMaisPeso = 1;
                printf("Sim. Em até %iT\n", quantidadePossivelQueSobrou);
            }else
            {
                possivelCarregarMaisPeso = 0;
                printf("Não\n");
            }

            if(possivelCarregarMaisPeso == 1)
            {
                printf("Procurando item com o valor que sobrou...\n");
                for (int i = 0; i <= 2; i++)
                {
                    int itemTetris = matriz[i][0];
                    int pesoTetris = matriz[i][1];
                    int valorTetris = matriz[i][2];

                    if(pesoTetris == quantidadePossivelQueSobrou)
                    {
                        printf("Item encontrado:\n");
                        printf("Item: %i, Peso: %i, Valor: R$%i\n", itemTetris, pesoTetris, valorTetris);

                        printf("É possível carregar mais peso: ");
                        quantidadePossivelQueSobrou = quantidadePossivelQueSobrou - pesoTetris;
                        dinheiroRetornado = dinheiroRetornado + valorTetris;

                        if(quantidadePossivelQueSobrou > 0)
                        {
                            printf("Sim. É possível.\n");
                            goto VerificarSobras;
                        }else
                        {
                            printf("Não é possível\n");
                        }
                    }
                }
            }
            printf("Valor total da solução atual: R$%i\n", dinheiroRetornado);
            printf("__________________________________________\n\n");
        }
    }
    
}

void buscarMelhorSolucao()
{
    int maiorValor = 0;
    for (int i = 0; i <= 2; i++)
    {
        if(maiorValor < melhoresSolucoes[i])
        {
            maiorValor = melhoresSolucoes[i];
        }
    }
    
    printf("\nMaior valor = R$%i", maiorValor);
}

int main()
{
    imprimirMatriz();
    calcularSolucoes();
    buscarMelhorSolucao();
}