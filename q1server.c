#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include <sys/types.h>

int main(int argc, char * argv[]) {
int socket_desc, client_sock, c, read_size; //Declare socket variable and size
struct sockaddr_in server, client; // declare socket structure
char buffer[5];
srand(time(NULL));
int n;

//Create socket
socket_desc = socket(AF_INET, SOCK_STREAM, 0); //Declare socket descriptor
if (socket_desc == -1) // catching socket creation error
  {
    printf("Could not create socket");
  }

  puts("Socket created");

   //Prepare the sockaddr_in structure
   server.sin_family = AF_INET; //address family for the socket
   server.sin_addr.s_addr = INADDR_ANY; //address for incoming request
   server.sin_port = htons(8080); //port designated for binding
//Bind or assigns a name to a socket.
if (bind(socket_desc, (struct sockaddr * ) & server, sizeof(server)) < 0)
  {
    //print the error message
    perror("bind failed. Error");
    return 1;
  }
   puts("bind done");

//Listen to a port for any incoming request for maximum 3 connection
    listen(socket_desc, 3);
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    if (client_sock < 0) //handling socket error
     {
        perror("accept failed");
        return 1;
     }

   puts("Connection accepted");

//while looping and accepts a new connection on a socket and returns a new file>
   client_sock = accept(socket_desc, (struct sockaddr * ) & client, (socklen_t >
   for (int i = 0; i < 1; i++) {
   bzero(buffer, 4);

  if (n < 0) perror("ERROR reading from socket");
}
return 0;
}
