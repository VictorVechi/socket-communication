#include "server-socket/ServerService.h"
#include <stdio.h>
#include <stdlib.h>
#include "cmos/CmosService.h"

#define PORTA 8080

int main() {
    printf("Container Server Iniciado\n");
    printf("Servidor iniciado na porta %d\n", PORTA);
    fflush(stdout);
    server(PORTA);
    return 0; 
}