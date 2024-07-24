#include "cmos/CmosService.h"
#include "client-socket/ClientService.h"
#include <stdio.h>
#define PORTA 8080

int main() {
    printf("cliente enviando msg na porta %d\n", PORTA);
    client(PORTA);

    return 0;
}