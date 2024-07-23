#include "server-socket/ServerService.h"
#include <stdio.h>
#define PORTA 8080

int main() {
    printf("Servidor iniciado na porta %d\n", PORTA);
    server(PORTA);
    return 0; 
}