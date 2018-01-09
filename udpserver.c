#include"myheaders.h"
int main(){
   int udpsocket,nbytes;
   char buffer[1024];
   struct sockaddr_in serveraddr,clientaddr;
   struct sockaddr_storage serverstorage;
   socklen_t addr_size,client_addr_size;
   int i;
  
udpsocket= socket(AF_INET,SOCK_DGRAM,0);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(7891);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
memset(serveraddr.sin_zero,'\0',sizeof serveraddr.sin_zero);

bind(udpsocket,(struct sockaddr *)&serveraddr,sizeof(serveraddr));

addr_size=sizeof serverstorage;

while(1){
   nbytes=recvfrom(udpsocket,buffer,1024,0,(struct sockaddr *)&serverstorage,&addr_size);

for(i=0;i<nbytes-1;i++)
 buffer[i]=toupper(buffer[i]);
 sendto(udpsocket,buffer,nbytes,0,(struct sockaddr *)&serverstorage,addr_size);
 }
}
