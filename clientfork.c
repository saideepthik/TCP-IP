#include"myheaders.h"
int main(int argc,char **argv)
{
if(argc<3)
{
puts("input format:client_exe well_known port_no server ip");
return;
}
int fd;
puts("creating server socket");
fd=socket(AF_INET,SOCK_STREAM,0);
if(fd<0)
{perror("socket");return;
}
puts("client socket created");
struct sockaddr_in addr;
int len=sizeof(addr);
puts("binding...");
addr.sin_family=AF_INET;
addr.sin_port=atoi(argv[1]);
addr.sin_addr.s_addr=inet_addr(argv[2]);
if(connect(fd,(const struct sockaddr *)&addr,len)<0)
{perror("client");close(fd);return;}
puts("connect success");
char buff[100];int status;
while(1)
{
puts("enter message for server");
gets(buff);
status=send(fd,buff,100,0);
if(status<0)
{perror("send");}
puts("waiting for echoes");
memset(buff,0,100);
status=recv(fd,buff,100,0);
if(status<0)
{perror("recv");}
else if(status==0)
{puts("server abruptly terminated");
}
else
{
printf("client received:%s\n",buff);
}
if(strcmp(buff,"quit")==0)
{
puts("client formally terminating connection with server");
exit(0);
}
}
close(fd);
}

