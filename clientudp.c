#include"myheaders.h"
int main()
{
int clientsocket,portnum,nbytes;
char buffer[1024];
puts("creating server socket");
if((clientsocket=socket(AF_INET,SOCK_DGRAM,0))==-1)
{perror("socket");return;
}
puts("client socket created");
struct sockaddr_in addr;
socklen_t addr_size;

puts("binding...");
addr.sin_family=AF_INET;
addr.sin_port=htons(7891);
addr.sin_addr.s_addr=inet_addr("127.0.0.1");
memset(addr.sin_zero,'\0',sizeof addr.sin_zero);

addr_size=sizeof addr;
while(1)
{
puts("enter message for server");
fgets(buffer,1024,stdin);
printf("you typed: %s",buffer);

nbytes=strlen(buffer)+1;

sendto(clientsocket,buffer,nbytes,0,(struct sockaddr *)&addr,addr_size);

nbytes=recvfrom(clientsocket,buffer,1024,0,NULL,NULL);
printf("received from server: %s\n",buffer);
}
}

