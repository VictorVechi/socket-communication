#include <stdio.h>
#include <time.h>
#include "CmosService.h"

void obterHorario() {
    time_t t;
    struct tm *tmp;
    char buffer[64];

    time(&t);
    tmp = localtime(&t);    

    if (tmp != NULL) {
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tmp);
        printf("Horário atual: %s\n", buffer);
    } else {
        printf("Erro ao obter o horário.\n");
    }
}