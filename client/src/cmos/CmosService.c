#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void atualizarDataHora(const char* dataHora) {
    struct timeval tempoValor;
    struct tm tempoEstrutura = {0};

    if (strptime(dataHora, "%Y-%m-%d %H:%M:%S", &tempoEstrutura) == NULL) {
        perror("Erro ao converter data e hora");
        return;
    }

    tempoValor.tv_sec = mktime(&tempoEstrutura);
    if (tempoValor.tv_sec == -1) {
        perror("Erro ao converter data e hora para segundos desde o Epoch");
        return;
    }

    tempoValor.tv_usec = 0;

    if (settimeofday(&tempoValor, NULL) != 0) {
        perror("Erro ao atualizar data e hora");
    }
}

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