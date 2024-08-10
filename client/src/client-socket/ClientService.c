#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "ClientService.h"
#include "../cmos/CmosService.h"

#define SERVER_IP "10.10.42.2"

void tratarErro(const char *mensagem) {
    perror(mensagem);
    exit(1);
}

int client(int porta_server)  {
    int socketClient;
    struct sockaddr_in enderecoServer;
    char buffer[256] = "QWxpY2U6aG9yYXJpbw==";
    char response_buffer[256];
    int bytesReceived;

    //https://pubs.opengroup.org/onlinepubs/007908799/xns/socket.html
    //int socket(int domain, int type, int protocol);
    //AF_INET -> dominio internet, SOCK_STREAM -> comunicacao TCP
    socketClient = socket(AF_INET, SOCK_STREAM, 0);

    enderecoServer.sin_family = AF_INET;
    enderecoServer.sin_port = htons(porta_server);
    enderecoServer.sin_addr.s_addr = inet_addr(SERVER_IP);

    if(connect(socketClient, (struct sockaddr *) &enderecoServer, sizeof(enderecoServer)) < 0) 
        tratarErro("ERRO ao conectar no servidor");

    if(write(socketClient, buffer, strlen(buffer)) < 0){
        tratarErro("ERRO ao enviar mensagem para o servidor");
    }

    //https://pubs.opengroup.org/onlinepubs/007908799/xns/recv.html
    //0 para rodar o recv sem nenhuma modificacao, talvez WAITALL seja util com o horario
    bytesReceived = recv(socketClient, response_buffer, sizeof(response_buffer), 0);

    if(bytesReceived < 0){
        tratarErro("ERRO ao receber mensagem do servidor");
    } else {
        printf("resposta do servidor %s\n", response_buffer);
        if(strcmp(response_buffer, "Chave incorreta") == 0){
           tratarErro("Chave inválida informada.");
        }
        printf("atualizando horario\n");
        atualizarDataHora(response_buffer);
    }
    
    close(socketClient);    

    return 0;
}