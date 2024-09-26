#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agencia.h"
#include "contaBancaria.h"

// Função auxiliar para limpar o buffer de entrada de forma portátil
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
