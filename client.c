#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage:./a.out portno ip address\n");
		printf("ex:./c 2000 127.0.0.1\n");
		return;
	}
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	perror("socket created successfully\n");
	struct sockaddr_in serverid;
	serverid.sin_family=AF_INET;
	serverid.sin_port=htons(atoi(argv[1]));
	serverid.sin_addr.s_addr=inet_addr(argv[2]);
	int len=sizeof(serverid);
	if(connect(sfd,(struct sockaddr*)&serverid,len)<0)
	{
		perror("connect");
		return;
	}
	printf(" connevted to server\n");
	while(1)
	{
	char m1[100],m2[100];
	 if(fork()==0)
	 {
		 while(1)
		 {
			 printf("enter the message to send\n");
			 scanf("%s",m1);
			 write(sfd,m1,strlen(m1)+1);
		 }
	 }
	 else
	 {
		 while(1)
		 {
			 read(sfd,m2,sizeof(m2));
			 printf("message:%s\n",m2);
		 }
	 }
	}
	close(sfd);
}
