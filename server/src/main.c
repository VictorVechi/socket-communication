#include "server-socket/ServerService.h"
#include <stdio.h>
#include "cmos/CmosService.h"
#define PORTA 8080

int main() {
    printf("Servidor iniciado na porta %d\n", PORTA);
    server(PORTA);
    obterHorario();
    return 0; 
}