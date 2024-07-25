#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "CmosService.h"

char* getHorario() {
    time_t tempoAtual;
    struct tm *estruturaTempo;
    char *bufferHorario = (char*)malloc(64 * sizeof(char));

    if (bufferHorario == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    time(&tempoAtual);
    estruturaTempo = localtime(&tempoAtual);

    if (estruturaTempo != NULL) {
        strftime(bufferHorario, 64, "%Y-%m-%d %H:%M:%S", estruturaTempo);
    } else {
        printf("Erro ao obter o horário.\n");
        free(bufferHorario);
        return NULL;
    }

    return bufferHorario;
}