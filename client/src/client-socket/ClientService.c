#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "ClientService.h"

int client(int porta_server)  {
    int socketClient;
    struct sockaddr_in enderecoServer;
    char buffer[256] = "hello world!";

    //https://pubs.opengroup.org/onlinepubs/007908799/xns/socket.html
    //int socket(int domain, int type, int protocol);
    //AF_INET -> dominio internet, SOCK_STREAM -> comunicacao TCP
    socketClient = socket(AF_INET, SOCK_STREAM, 0);

    enderecoServer.sin_family = AF_INET;
    enderecoServer.sin_port = htons(porta_server);
    enderecoServer.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(socketClient, (struct sockaddr *) &enderecoServer, sizeof(enderecoServer)) < 0) 
        perror("error no bind");

    if(write(socketClient, buffer, strlen(buffer)) < 0){
        perror("Erro ao enviar msg");
    }

    close(socketClient);    

    return 0;
}