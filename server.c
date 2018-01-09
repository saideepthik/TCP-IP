#include"myheaders.h"
void client_info(int ,struct sockaddr_in );
int main(int argc,char **argv)
{
if(argc<2)
{
puts("input format:server_exe well_known port_no");
return;
}
int sfd;
puts("creating server socket");
sfd=socket(AF_INET,SOCK_STREAM,0);
if(sfd<0)
{perror("socket");return;
}
puts("server socket created");
struct sockaddr_in saddr;
int slen=sizeof(saddr);
puts("binding...");
saddr.sin_family=AF_INET;
saddr.sin_port=atoi(argv[1]);
saddr.sin_addr.s_addr=inet_addr("0.0.0.0");
if(bind(sfd,&saddr,slen)<0)
{perror("bind");close(sfd);return;}
puts("bind success");
puts("creating connections queue for only 1");
if(listen(sfd,1)<0)
{
perror("listen");close(sfd);return;}
puts("connection queue created");
struct sockaddr_in caddr;
int clen=sizeof(caddr),newfd;
puts("waiting passively for connection from any client");
newfd=accept(sfd,&caddr,&clen);
if(newfd<0)
{perror("accept");close(sfd);return;}
puts("connection with client");
client_info(newfd,caddr);
char buff[100];int status;
puts("waiting for message from client\n");
status=recv(newfd,buff,100,0);
if(status<0)
{perror("recv");}
else if(status==0)
{puts("client abruptly terminated");
}
else
{
printf("server received:%s\n",buff);
printf("server echoes\n");
}
status=send(newfd,buff,100,0);
if(status<0)
{perror("send");}
if(strcmp(buff,"quit")==0)
{
puts("client formally terminating connection with server");
close(newfd);close(sfd);return;
}
close(newfd);
close(sfd);
}

void client_info(int newfd,struct sockaddr_in caddr)
{
puts("whose");
char *p=inet_ntoa(caddr.sin_addr);
unsigned short portno=ntohs(caddr.sin_port);
printf("ip address is :%s\n",p);
printf("ephemeral port is :%d\n",portno);
printf("file descriptor is:%d\n",newfd);
}
