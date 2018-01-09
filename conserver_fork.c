#include"myheaders.h"
void client_info(int ,struct sockaddr_in );
int sighandler(int x)
{
int status;
wait(&status);
printf("some client exited\n");
}
int main(int argc,char **argv)
{
if(argc<2)
{
puts("input format:server_exe well_known port_no");
return;
}
int sfd;
signal(SIGCHLD,sighandler);
puts("creating server socket");
sfd=socket(AF_INET,SOCK_STREAM,0);
if(sfd<0)
{perror("socket");return;
}
puts("server socket created");
puts("to avoid bind error: address already in user");
int val=1;
if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&val,4)<0)
{
perror("bind");close(sfd);return;}
puts("setsockopt success");
struct sockaddr_in saddr;
int slen=sizeof(saddr);
puts("binding...");
saddr.sin_family=AF_INET;
saddr.sin_port=atoi(argv[1]);
saddr.sin_addr.s_addr=inet_addr("0.0.0.0");
if(bind(sfd,(const struct sockaddr *)&saddr,slen)<0)
{perror("bind");close(sfd);return;}
puts("bind success");
puts("creating connections queue for only 1");
if(listen(sfd,1)<0)
{
perror("listen");close(sfd);return;}
puts("connection queue created");
struct sockaddr_in caddr;
int clen=sizeof(caddr),newfd;
while(1)
{
puts("waiting passively for connection from any client");
newfd=accept(sfd,&caddr,&clen);
if(newfd<0)
{perror("accept");close(sfd);return;}
char buff[100];int status;
if(fork()==0)
{
while(1)
{
puts("connection with client");
client_info(newfd,caddr);
//char buff[100];int status;
puts("waiting for message from client");
status=recv(newfd,buff,100,0);
if(status<0)
{perror("recv");}
else if(status==0)
{
puts("client abruptly terminated");
}
else
{
printf("server received:\n%s\n",buff);
printf("server echoes\n");
}
status=send(newfd,buff,100,0);
if(status<0)
{perror("send");}
if(strcmp(buff,"quit")==0)
{
puts("client formally terminating connection with server");
exit(0);
}
}// inner while
close(newfd);
exit(0);
}//inner if for fork
}//outer while
exit(0);
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
