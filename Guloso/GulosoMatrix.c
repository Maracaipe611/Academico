#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int distanciasHorizontal[4][3] = {
    {1, 5, 2},
    {7, 1, 3},
    {5, 2, 2},
    {2, 4, 1}
};

static int distanciaVertical[3][3] = {
    {0, 4, 1},
    {3, 2, 4},
    {4, 2, 8}
};

static char cidades[4][4] = {
    {'q', 'c', 'e', 'h'},
    {'d', 'f', 'i', 'l'},
    {'g', 'j', 'm', 'o'},
    {'k', 'n', 'p', 'r'}
};

int valorPercorridoHorizontalmente(int localizacaoPrimeiraCidade[2], int localizacaoSegundaCidade[2])
{
    int valorPercorrido = 0;
    int numeroDaLinha = localizacaoPrimeiraCidade[0];
    int colunaPrimeiraCidade = localizacaoPrimeiraCidade[1];
    int colunaSegundaCidade = localizacaoSegundaCidade[1];

    int cidadesEntreElas = colunaSegundaCidade - colunaPrimeiraCidade;
    printf("Numero da Coluna: %i, Linha:\nPrimeira Cidade: %i, Segunda cidade: %i\nDistância entre as duas casas: %i", numeroDaLinha, colunaPrimeiraCidade, colunaSegundaCidade, cidadesEntreElas);

    if (cidadesEntreElas < 0)
    {
        cidadesEntreElas = cidadesEntreElas * -1;
    }

    if (cidadesEntreElas == 1) //calcular apenas a distancia entre as duas
    {
        if (colunaPrimeiraCidade >= colunaSegundaCidade)
        {
            valorPercorrido = distanciasHorizontal[colunaPrimeiraCidade - 1][numeroDaLinha];
        }
        else if (colunaSegundaCidade > colunaPrimeiraCidade)
        {
            valorPercorrido = distanciasHorizontal[colunaSegundaCidade - 1][numeroDaLinha];
        }
    }

    if (cidadesEntreElas == 2)
    {
        if (colunaSegundaCidade == 3) //Calcular duas ultimas casas
        {
            for (int i = 1; i <= 2; i++)
            {
                valorPercorrido = valorPercorrido + distanciasHorizontal[colunaPrimeiraCidade + i][numeroDaLinha];
            }
        }
        else if (colunaSegundaCidade <= 2)
        {
            for (int i = 0; i <= 1; i++)
            {
                valorPercorrido = valorPercorrido + distanciasHorizontal[colunaPrimeiraCidade + i][numeroDaLinha];
            }
        }
    }

    if (cidadesEntreElas == 3) //calcular a distancia de toda a coluna
    {
        for (int i = 0; i <= 2; i++)
        {
            valorPercorrido = valorPercorrido + distanciasHorizontal[i][numeroDaLinha];
        }
    }

    return valorPercorrido;
}

int valorPercorridoVerticalmente(int localizacaoPrimeiraCidade[2], int localizacaoSegundaCidade[2])
{
    int valorPercorrido = 0;
    int numeroDaColuna = localizacaoPrimeiraCidade[1];
    int linhaPrimeiraCidade = localizacaoPrimeiraCidade[0];
    int linhaSegundaCidade = localizacaoSegundaCidade[0];

    int cidadesEntreElas = linhaSegundaCidade - linhaPrimeiraCidade;
    printf("Numero da coluna: %i, colunas\nPrimeira Cidade: %i, Segunda cidade: %i\nDistância entre as duas casas: %i\n", numeroDaColuna, linhaPrimeiraCidade, linhaSegundaCidade, cidadesEntreElas);

    if (cidadesEntreElas < 0)
    {
        cidadesEntreElas = cidadesEntreElas * -1;
    }

    if (cidadesEntreElas == 1)
    {
        if (linhaPrimeiraCidade >= linhaSegundaCidade)
        {
            valorPercorrido = distanciaVertical[linhaPrimeiraCidade - 1][numeroDaColuna];
        }
        else if (linhaSegundaCidade > linhaPrimeiraCidade)
        {
            valorPercorrido = distanciaVertical[linhaSegundaCidade - 1][numeroDaColuna];
        }
    }

    if (cidadesEntreElas == 2)
    {
        if (linhaSegundaCidade == 3) //Calcular duas ultimas casas
        {
            for (int i = 1; i <= 2; i++)
            {
                valorPercorrido = valorPercorrido + distanciaVertical[i][numeroDaColuna];
            }
        }
        else if (linhaSegundaCidade <= 2)
        {
            for (int i = 0; i <= 1; i++)
            {
                valorPercorrido = valorPercorrido + distanciaVertical[linhaPrimeiraCidade + i][numeroDaColuna];
            }
        }
    }

    if (cidadesEntreElas == 3)
    {
        for (int i = 0; i <= 2; i++)
        {
            valorPercorrido = valorPercorrido + distanciaVertical[i][numeroDaColuna];
        }
    }

    return valorPercorrido;
}

int calcularDistanciaEntreDuasCidades(char primeiraCidade, char segundaCidade)
{
    int localizacaoPrimeiraCidade[2];
    int localizacaoSegundaCidade[2];
    int valorPercorrido = 0;

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            if(cidades[i][j] == primeiraCidade)
            {
                localizacaoPrimeiraCidade[0] = i;
                localizacaoPrimeiraCidade[1] = j;
            }

            if(cidades[i][j] == segundaCidade)
            {
                localizacaoSegundaCidade[0] = i;
                localizacaoSegundaCidade[1] = j;
            }
        }
    }

    printf("Localização da 1ª cidade: (%i, %i)\n", localizacaoPrimeiraCidade[0], localizacaoPrimeiraCidade[1]);
    printf("Localização da 2ª cidade: (%i, %i)\n\n\n", localizacaoSegundaCidade[0], localizacaoSegundaCidade[1]);

    char *tipoDistancia = malloc(100);

    if(localizacaoPrimeiraCidade[0] == localizacaoSegundaCidade[0])
    {
        printf("São cidades da mesma linha. Distância está na horizontal\n");
        strcpy(tipoDistancia, "horizontal");
    }else
    {
        printf("São cidades da mesma coluna. Distância está na vertical\n");
        strcpy(tipoDistancia, "vertical");
    }

    if(strcmp(tipoDistancia, "horizontal") == 0)
    {
        valorPercorrido = valorPercorridoHorizontalmente(localizacaoPrimeiraCidade, localizacaoSegundaCidade);
    }else
    if(strcmp(tipoDistancia, "vertical") == 0)
    {
        valorPercorrido = valorPercorridoVerticalmente(localizacaoPrimeiraCidade, localizacaoSegundaCidade);
    }
    
    printf("\nValor Percorrido: %i\n", valorPercorrido);
    return valorPercorrido;
}

int valorTotalEntreAsCasas(char primeiraCasa, char segundaCasa)
{
    int distanciaVertical[2] = {0,0};
    int distanciaHorizontal[2] = {0,0};
    int distanciaVerticalTotal = 0;
    int distanciaHorizontalTotal = 0;
    int primeiraCasaCoordenadas[2] = {0,0};
    int segundaCasaCoordenadas[2] = {0,0};

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            if(cidades[i][j] == primeiraCasa)
            {
                distanciaVertical[0] = i;
                distanciaHorizontal[0] = j;
                primeiraCasaCoordenadas[0] = i;
                primeiraCasaCoordenadas[1] = j;
            }

            if(cidades[i][j] == segundaCasa)
            {
                distanciaVertical[1] = i;
                distanciaHorizontal[1] = j;
                segundaCasaCoordenadas[0] = i;
                segundaCasaCoordenadas[1] = j;
            }
        }
    }
    printf("Pontos da distancia horizontal: (%i, %i)\n\n", distanciaHorizontal[1], distanciaHorizontal[0]);
    distanciaHorizontalTotal = distanciaHorizontal[1] - distanciaHorizontal[0];
    distanciaVerticalTotal = distanciaVertical[1] - distanciaVertical[0];

    if(distanciaHorizontalTotal < 0)
    {
        distanciaHorizontalTotal = distanciaHorizontalTotal * -1;
    }
    if(distanciaVerticalTotal < 0)
    {
        distanciaVerticalTotal = distanciaVerticalTotal * -1;
    }

    printf("Distancia vertical total: %i,\nDistância horizontal Total: %i\n", distanciaVerticalTotal, distanciaHorizontalTotal);

    int totalizarCaminhoEntrePontos = 0;

    if((distanciaVerticalTotal == 0 && distanciaVerticalTotal != 0) || 
        (distanciaHorizontalTotal != 0 && distanciaVerticalTotal == 0))
    {
        int distanciaMesmaLinha = calcularDistanciaEntreDuasCidades(primeiraCasa, segundaCasa);
        exit(0);
        return distanciaMesmaLinha;
    }
    
    int coordenadasAtuaisVerticais = primeiraCasaCoordenadas[0];
    int coordenadasAtuaisHorizontais = primeiraCasaCoordenadas[1];
    
    int menorValorVertical = 0;
    int menorValorHorizontal = 0;
    int contador = 0;

    buscarCasa:
    if(primeiraCasaCoordenadas[0] < 3 && primeiraCasaCoordenadas[1] < 2){
        menorValorVertical = calcularDistanciaEntreDuasCidades(cidades[coordenadasAtuaisVerticais][coordenadasAtuaisHorizontais], cidades[primeiraCasaCoordenadas[0] + 1][primeiraCasaCoordenadas[1]]); //qual o resultado da distancia entre a casa atual e a proxima casa
        menorValorHorizontal = calcularDistanciaEntreDuasCidades(cidades[coordenadasAtuaisVerticais][coordenadasAtuaisHorizontais], cidades[primeiraCasaCoordenadas[0]][primeiraCasaCoordenadas[1] + 1]);

        printf("Valor entre os vizinhos\nVerticais: %i,\nHorizontais: %i", menorValorVertical, menorValorHorizontal);
        if (menorValorHorizontal < menorValorVertical)
        {
            coordenadasAtuaisHorizontais = primeiraCasaCoordenadas[1] + 1;
            totalizarCaminhoEntrePontos = totalizarCaminhoEntrePontos + menorValorHorizontal;
        }
        else if (menorValorHorizontal >= menorValorVertical)
        {
            coordenadasAtuaisVerticais = primeiraCasaCoordenadas[0] + 1;
            totalizarCaminhoEntrePontos = totalizarCaminhoEntrePontos + menorValorVertical;
        }

    }else if(primeiraCasaCoordenadas[0] <= 3 && primeiraCasaCoordenadas[1] < 2)
    {
        menorValorHorizontal = calcularDistanciaEntreDuasCidades(cidades[coordenadasAtuaisVerticais][coordenadasAtuaisHorizontais], cidades[primeiraCasaCoordenadas[0]][primeiraCasaCoordenadas[1] + 1]);

        printf("Valor entre os vizinhos\n verticais: %i,\nHorizontais: %i", menorValorVertical, menorValorHorizontal);

        coordenadasAtuaisHorizontais = primeiraCasaCoordenadas[1] + 1;
        totalizarCaminhoEntrePontos = totalizarCaminhoEntrePontos + menorValorHorizontal;
        
        
    }else if(primeiraCasaCoordenadas[0] < 3 && primeiraCasaCoordenadas[1] <= 2){

        menorValorVertical = calcularDistanciaEntreDuasCidades(cidades[coordenadasAtuaisVerticais][coordenadasAtuaisHorizontais], cidades[primeiraCasaCoordenadas[0] + 1][primeiraCasaCoordenadas[1]]); //qual o resultado da distancia entre a casa atual e a proxima casa

        printf("Valor entre os vizinhos\n verticais: %i,\nHorizontais: %i", menorValorVertical, menorValorHorizontal);

        coordenadasAtuaisVerticais = primeiraCasaCoordenadas[0] + 1;
        totalizarCaminhoEntrePontos = totalizarCaminhoEntrePontos + menorValorVertical;
    }

    if(coordenadasAtuaisVerticais != segundaCasaCoordenadas[0] && coordenadasAtuaisHorizontais != segundaCasaCoordenadas[1])
    {
        goto buscarCasa;
    }

    return totalizarCaminhoEntrePontos;
}

int main()
{
    valorTotalEntreAsCasas('q', 'd');
    return 0;
}