#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int matriz[8][8];
static int maiorValor = 1;
static int pontoInicial = 1;
static bool matrizIncompleta = true;
static int pontosCondenados[100][4];
static int possiveisJogadas[8][2] = {
    {2, 1}, //k = 0
    {2, -1},
    {-2, 1},
    {-2, -1},
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2}};

void procurarUltimoPonto()
{
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            if (matriz[i][j] > maiorValor)
            {
                maiorValor = matriz[i][j];
                procurarUltimoPonto();
            }
        }
    }

    printf("Último número: %i\n", maiorValor);
}

bool aindaExistemCasasVazias()
{
    matrizIncompleta = false;

    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            if (matriz[i][j] == 0)
            {
                matrizIncompleta = true;
            }
        }
    }

    return matrizIncompleta;
}

void imprimirMatriz()
{
    for (int i = 0; i <= 7; i++)
    {
        printf("\t|");
        for (int j = 0; j <= 7; j++)
        {
            printf("%2d|", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------\n");
}

void imprimirMatrizCondenada(int matriz[100][4])
{
    for (int i = 0; i <= 99; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------\n");
}

void preencherMatriz()
{
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            matriz[i][j] = 0;
        }
        printf("\n");
    }
    matriz[0][4] = pontoInicial;
}

void preencherMatrizCondenada(int matriz[100][4])
{
    for (int i = 0; i <= 99; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

void condenarProximaCasa(int xAtual, int yAtual, int xProx, int yProx)
{
    int j = 0;
    bool coordNaoExiste = true;
    for (int i = 0; i <= 99; i++)
    {
        if (pontosCondenados[i][j] == xAtual &&
            pontosCondenados[i][j + 1] == yAtual &&
            pontosCondenados[i][j + 2] == xProx &&
            pontosCondenados[i][j + 3] == yProx)
        {
            coordNaoExiste = false;
            i = 99;
        }
    }

    if (coordNaoExiste)
    {
        for (int i = 0; i <= 99; i++)
        {
            if (pontosCondenados[i][j] == 0 &&
                 pontosCondenados[i][j + 1] == 0 &&
                 pontosCondenados[i][j + 2] == 0 &&
                 pontosCondenados[i][j + 3] == 0) 
            {
                printf("Condenando jogada... (%i, %i) -> (%i,%i)\n", xAtual, yAtual, xProx, yProx);
                pontosCondenados[i][j] = xAtual;
                pontosCondenados[i][j + 1] = yAtual;
                pontosCondenados[i][j + 2] = xProx;
                pontosCondenados[i][j + 3] = yProx;
                i = 99;
            }
        }
    }
}

bool proximaCasaNaoEstaCondenada(int xAtual, int yAtual, int xProx, int yProx)
{
    int j = 0;
    for (int i = 0; i <= 99; i++)
    {
        if (pontosCondenados[i][j] == xAtual &&
            pontosCondenados[i][j + 1] == yAtual &&
            pontosCondenados[i][j + 2] == xProx &&
            pontosCondenados[i][j + 3] == yProx)
        {
            printf("Próxima casa ESTÁ condenada\n\n");
            return false;
        }
        
    }
    printf("Próxima casa NÃO está condenada\n");
    return true;
}

void retrocederECondenar(int xAtual, int yAtual, int xProx, int yProx)
{
    matriz[xAtual][yAtual] = 0;

    if (maiorValor >= 1)
    {
        maiorValor = maiorValor - 1;
        printf("Retornando para o número: %i\n", maiorValor);
    }

    condenarProximaCasa(xAtual, yAtual, xProx, yProx);
    procurarUltimoPonto();
}

bool menorQueLimite(int xFuturo, int yFuturo)
{
    if (xFuturo >= 0 && xFuturo <= 7 && yFuturo >= 0 && yFuturo <= 7)
    {
        printf("próxima jogada menor que limite\n");
        return true;
    }

    printf("próxima jogada MAIOR que limite\n\n");
}

bool movimentoFuturoDisponivel(int futuraJogadaX, int futuraJogadaY)
{
    if (matriz[futuraJogadaX][futuraJogadaY] == 0 && maiorValor != matriz[futuraJogadaX][futuraJogadaY])
    {
        printf("Próxima casa está disponível\n");
        return true;
    }

    printf("Próxima casa está indisponível:\nNúmero: %i - [X futuro:%i, Y futuro:%i]\n\n",matriz[futuraJogadaX][futuraJogadaY], futuraJogadaX, futuraJogadaY);
    return false;
}

void preencherProximaCasa()
{
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            if (matriz[i][j] == maiorValor)
            {
                for (int k = 0; k <= 7; k++)
                {
                    for (int l = 0; l <= 0; l++)
                    {
                        printf("Cordenada Atual: Número: %i - X:%i, Y: %i\n", maiorValor, i, j);

                        int futuraJogadaX = i + possiveisJogadas[k][l];
                        int futuraJogadaY = j + possiveisJogadas[k][l + 1];

                        printf("Futura jogada: Número: %i - X:%i, Y: %i\nMovimento do cavalo: [%i,%i]\n",maiorValor+1, futuraJogadaX, futuraJogadaY, possiveisJogadas[k][l], possiveisJogadas[k][l + 1]);

                        if (menorQueLimite(futuraJogadaX, futuraJogadaY) && movimentoFuturoDisponivel(futuraJogadaX, futuraJogadaY) && proximaCasaNaoEstaCondenada(i, j, futuraJogadaX, futuraJogadaY))
                        {
                            matriz[futuraJogadaX][futuraJogadaY] = maiorValor + 1;
                            maiorValor = maiorValor + 1;
                            imprimirMatriz();
                            preencherProximaCasa();
                        }
                        else if( movimentoFuturoDisponivel(futuraJogadaX, futuraJogadaY) && proximaCasaNaoEstaCondenada(i, j, futuraJogadaX, futuraJogadaY))
                        {
                            printf("\n---RETROCEDENDO---\n");
                            retrocederECondenar(i, j, futuraJogadaX, futuraJogadaY);
                            for (int m = 0; m <= 7; m++)
                            {
                                for (int n = 0; n <= 7; n++)
                                {
                                    if (matriz[m][n] == maiorValor)
                                    {
                                        i = m;
                                        j = n;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int teste = 0;

    preencherMatriz();
    imprimirMatriz();
    preencherMatrizCondenada(pontosCondenados);
    printf("\n");

    procurarUltimoPonto();
    printf("\n");

    preencherProximaCasa();

    printf("\n");
    imprimirMatriz();

    return 0;
}