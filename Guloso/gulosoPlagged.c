//Estudantes:
//Aluno: Rodrigo de Souza Costa - 1920650
//Aluno: Yuri Moura Marques - 1920934

#include <stdio.h>
#include <stdlib.h>
#define tamanho 11



int inicio[tamanho] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12}; // inicio das atividades segundo PDF;
int fim[tamanho] =    {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

int menorFim() {

    int menorFinal= 0;
    int i;
    for(i = 0; i < tamanho; i++) {
        if(fim[menorFinal] > fim[i]) {
            menorFinal = i;
        }
    }

    return menorFinal;
}


int maiorInicio(int inicioFor, int final, int menorFinal){

    int menorInicio = 0;
    int i;

    for(i = inicioFor; i < final; i++)
    {
        if(inicio[i] > fim[menorFinal]) {
            if(inicio[menorInicio] > inicio[i] || menorInicio == 0) {
                menorInicio = i;
            }
        }
    }

    return menorInicio;
}

int verificarProximo(int index) 
{
    int i;
    for(i = 0; i < tamanho;  i++) {
        if(inicio[i] > fim[index]) {
            return 1;
        }
    }
    return 0;
}

int main()
{    
    int maiorInicioIndex = 0;
    int indexes[tamanho];
    int menorFinalIndex = menorFim();
    int menorFinalValue = fim[menorFinalIndex];
    int k =0;

    int continuaBusca = 1;
    while(continuaBusca){
        if(k == 0){
            indexes[k] = menorFinalIndex;
        }
        maiorInicioIndex = maiorInicio(0, tamanho, menorFinalIndex);
        menorFinalIndex = maiorInicioIndex;
        menorFinalValue = fim[menorFinalIndex];
        k++;
        indexes[k] = menorFinalIndex;
        continuaBusca = verificarProximo(menorFinalIndex);
    }
    int i = 0;
    for(i = 0; i <= k ; i++)
    {
        printf("\nAtividades mutualmente compativeis: %i", indexes[i] + 1);
    }
}

//Index[0,3,7,10]