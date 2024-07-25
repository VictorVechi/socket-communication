#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "ClientService.h"

#define SERVER_IP "192.168.1.2"

int client(int porta_server)  {
    int socketClient;
    struct sockaddr_in enderecoServer;
    char buffer[256] = "hello world!";
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
        perror("error no bind");

    if(write(socketClient, buffer, strlen(buffer)) < 0){
        perror("Erro ao enviar msg");
    }

    //https://pubs.opengroup.org/onlinepubs/007908799/xns/recv.html
    //0 para rodar o recv sem nenhuma modificacao, talvez WAITALL seja util com o horario
    bytesReceived = recv(socketClient, response_buffer, sizeof(response_buffer), 0);

    if(bytesReceived < 0){
        perror("erro ao receber msg");
    } else {
        printf("resposta do servidor %s\n", response_buffer);
    }
    

    close(socketClient);    

    return 0;
}