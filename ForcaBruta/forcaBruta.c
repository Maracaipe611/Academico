#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *possivelSenha = "";
    char** alfabeto[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    for (int primeiraLetra = 0; primeiraLetra < 25; primeiraLetra++)
    {
        possivelSenha = strcat(possivelSenha, alfabeto[primeiraLetra]);
        printf("%s", possivelSenha);
    }
    

    return 0;
}