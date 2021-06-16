#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char alphabet[] =
"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%¨&*()_+{}?:^`´[]~";

static const int alphabetSize = sizeof(alphabet) - 1;

char possiblePass[5];

void ImplementarSenha()
{
    printf("%i", alphabetSize);
    printf("%s", alphabet[85]);
    for (int i = 0; i >= alphabetSize; i++)
    {
        possiblePass[1] = alphabet[i];
        printf("%s\n", possiblePass[i]);
    }
    
}

int main()
{
    ImplementarSenha();
    return 0;
}