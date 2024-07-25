#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "ServerService.h"
#include "../cmos/CmosService.h"

#define KEY "QWxpY2U6aG9yYXJpbw=="

void tratarErro(const char *mensagem) {
    perror(mensagem);
    exit(1);
}

int server(int portaServidor) {
    struct sockaddr_in enderecoServidor, enderecoCliente;
    
    int socketServidor, socketCliente;
    socklen_t tamanhoCliente;
    char buffer[256];
    int numeroBytes;
    bool isOpen = true;

    enderecoServidor.sin_family = AF_INET;
    enderecoServidor.sin_addr.s_addr = htonl(INADDR_ANY);
    enderecoServidor.sin_port = htons(portaServidor);

    socketServidor = socket(AF_INET, SOCK_STREAM, 0);

    if (socketServidor < 0) tratarErro("ERRO ao abrir o socket");

    if (bind(socketServidor, (struct sockaddr *) &enderecoServidor, sizeof(enderecoServidor)) < 0) 
        tratarErro("ERRO ao fazer o bind");

    listen(socketServidor, 5);
    tamanhoCliente = sizeof(enderecoCliente);

    while (isOpen) {
        socketCliente = accept(socketServidor, (struct sockaddr *) &enderecoCliente, &tamanhoCliente);
        if (socketCliente < 0) tratarErro("ERRO ao aceitar\n");
        if (socketCliente > 0) printf("Conexão aceita\n");

        numeroBytes = recv(socketCliente, buffer, sizeof buffer, 0);
        buffer[numeroBytes] = '\0';

        if(strcmp(buffer, KEY) == 0) {
            printf("Chave correta\n");
            char *horario = getHorario();
            send(socketCliente, horario, numeroBytes, 0);
        }
        
        puts(buffer);
        fflush(stdout);

        close(socketCliente);
    }

    close(socketServidor);
    return 0; 
}