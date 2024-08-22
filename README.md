<div>
  
# Projeto de Redes de Computadores
  
<p>
Este projeto foi desenvolvido como parte da avaliação parcial da disciplina de Redes de Computadores do curso de Ciência da Computação. O objetivo era solucionar o problema de uma personagem fictícia chamada Alice. Alice enfrentava um problema com a bateria CMOS de seu computador, que estava esgotada. Como resultado, sempre que ela ligava o computador, ele iniciava com o horário incorreto.

O computador de Alice utilizava um certificado de autenticidade local para assinar digitalmente seus documentos, o que exigia a data e hora corretas. Ela não conseguia ajustar manualmente o horário do computador, pois não possuía privilégios de administrador. Além disso, o modelo de sua placa-mãe era muito antigo, e os componentes necessários já não eram mais fabricados.

A solução proposta para o problema de Alice foi desenvolver uma comunicação cliente-servidor entre um computador com data e hora corretas e o computador de Alice, atualizando-o para refletir o tempo correto.
</p>

## Requisitos
<p>
Para executar o projeto em sua máquina é necessário ter as ferramentas a seguir instaladas em seu computador:
</p>
<ul> 
    <li>Docker</li>
</ul>

## Como executar o projeto

1. Clone o repositório para executar localmente
```bash
# Clonando o repositório
$ git clone https://github.com/VictorVechi/socket-communication.git
$ cd socket-communication
```
<p><strong>Todos os comandos a seguir deverão ser executados na pasta do projeto</strong></p>

2. Antes de executar o projeto, é necessário buildar os containers docker:

```bash
# Buildando os containers
$ docker compose build
```
3. Após buildar os containers, já é possível rodar o projeto:

```bash
# Rodando o servidor
$ docker compose up server
```

#### Uma vez que o servidor já esteja pronto, em um novo terminal, rode o cliente:

```bash
# Rodando o cliente
$ docker compose up client
```
