#include"header.h"
struct msgbuf
{
	long mtype;
	char mtext[100];
};
void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage:./a.out portno ip address\n");
		printf("ex:./c 2000 127.0.0.1\n");
		return;
	}
        int qid=msgget(4,IPC_CREAT|0664);
	if(qid<0)
	{
		perror("msgget");
		return;
	}
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	perror("socket");
	struct sockaddr_in serverid,clientid;
	serverid.sin_family=AF_INET;
	serverid.sin_port=htons(atoi(argv[1]));
	serverid.sin_addr.s_addr=inet_addr(argv[2]);
	int len=sizeof(serverid);
	if(bind(sfd,(struct sockaddr*)&serverid,len)<0)
	{
		perror("bind");
		return;
	}
	perror("bind");
	if(listen(sfd,5)<0)
	{
		perror("listen");
		return;
	}
	perror("listen");
	printf("waiting for cliemt request\n");
	int nsfd1,nsfd2;
	 nsfd1=accept(sfd,(struct sockaddr*)&clientid,&len);
	if(nsfd1<0)
		{
			perror("accept");
			return;
		}
		perror("accept");
		printf("client1 connected\n");
	       nsfd2=accept(sfd,(struct sockaddr *)&clientid,&len);
	       printf("client2  connected\n");
	       while(1)
	       {
		if(fork()==0)
		{
			struct msgbuf v;
			v.mtype=1;
			read(nsfd1,v.mtext,sizeof(v.mtext));
			msgsnd(qid,&v,sizeof(v.mtext),0);
			exit(0);
		}
		if(fork()==0)
		{
			struct msgbuf v;
			msgrcv(qid,&v,sizeof(v.mtext),1,0);
			write(nsfd2,v.mtext,strlen(v.mtext)+1);
			exit(0);
		}
		if(fork()==0)
		{
			struct msgbuf v;
			v.mtype=2;
			read(nsfd2,v.mtext,sizeof(v.mtext));
			msgsnd(qid,&v,sizeof(v.mtext),0);
			exit(0);
		}
		if(fork()==0)
		{
			struct msgbuf v;
			msgrcv(qid,&v,sizeof(v.mtext),2,0);
			write(nsfd1,v.mtext,strlen(v.mtext)+1);
			exit(0);
		}
	       }
		close(nsfd1);
		close(nsfd2);
		close(sfd);
		msgctl(qid,IPC_RMID,NULL);
	       }
