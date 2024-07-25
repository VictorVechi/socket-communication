#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "CmosService.h"

char* obterHorario() {
    time_t t;
    struct tm *tmp;
    char *buffer = (char*)malloc(64 * sizeof(char));

    if (buffer == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    time(&t);
    tmp = localtime(&t);

    if (tmp != NULL) {
        strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", tmp);
    } else {
        printf("Erro ao obter o horário.\n");
        free(buffer);
        return NULL;
    }

    return buffer;
}