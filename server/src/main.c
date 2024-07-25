#include "server-socket/ServerService.h"
#include <stdio.h>
#include <stdlib.h>
#include "cmos/CmosService.h"
#define PORTA 8080

int main() {
    printf("Servidor iniciado na porta %d\n", PORTA);
    //server(PORTA);
    char *horario = obterHorario();
    if (horario != NULL) {
        printf("Horário atual: %s\n", horario);
        free(horario);
    }
    return 0; 
}