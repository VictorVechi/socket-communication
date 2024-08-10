#include "cmos/CmosService.h"
#include "client-socket/ClientService.h"
#include <stdio.h>
#include <unistd.h>
#define PORTA 8080

int main() {
    const char* dataHora = "2000-1-1 00:00:00";
    atualizarDataHora(dataHora);
    
    char* horario = getHorario();

    printf("Cliente enviando mensagem na porta %d\n", PORTA);
    printf("Horário atual: %s\n", horario);

    sleep(1);

    client(PORTA);

    horario = getHorario();
    printf("Horário atual: %s\n", horario);
    return 0;
}