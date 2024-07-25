#include "cmos/CmosService.h"
#include "client-socket/ClientService.h"
#include <stdio.h>
#include <unistd.h>
#define PORTA 8080

int main() {
    printf("cliente enviando msg na porta %d\n", PORTA);
    sleep(5);
    client(PORTA);

    return 0;
}