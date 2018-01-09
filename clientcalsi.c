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
struct calsi v;int status;
puts("enter a and b values to calculate:");
scanf("%d %d",&v.x,&v.y);
puts("choose an operator +,*,-,/,%");
getchar();
scanf("%c",&v.c);
status=send(fd,&v,10,0);
if(status<0)
{perror("send");}
puts("waiting for echoes");
//memset(v,0,100);
int r;
status=recv(fd,&r,10,0);
if(status<0)
{perror("recv");}
else if(status==0)
{puts("server abruptly terminated");
}
else
{
printf("client received:%d\n",r);
}
/*if(strcmp(buff,"quit")==0)
{
puts("server formally terminating connection with client");
}*/
close(fd);
}

