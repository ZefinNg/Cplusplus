#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st
{
	long int my_msg_type;
	char some_text[BUFSIZ];
};

int main(void)
{
	int running = 1;
	struct my_msg_st some_data;
	int msgid = 0;
	char buffer[BUFSIZ] = {0};
	memset((void*)&some_data, 0, sizeof(some_data));

	/*创建消息队列*/
	msgid=msgget((key_t)1234,0666 | IPC_CREAT);
	if(msgid==-1)
	{
		fprintf(stderr,"msgget failed with error:%d\n",errno);
		exit(EXIT_FAILURE);
	}

	/*循环向消息队列中添加消息*/
	while(running)
	{
		memset(buffer, 0, sizeof(buffer));
		printf("Enter some text:");
		fgets(buffer,BUFSIZ,stdin);
		some_data.my_msg_type=1;
		strcpy(some_data.some_text,buffer);

		/*添加消息*/
		if(msgsnd(msgid,(void *)&some_data,BUFSIZ,0)==-1)
		{
			fprintf(stderr,"msgsed failed\n");
			exit(EXIT_FAILURE);
		}

		/*用户输入的为“end”时结束循环*/
		if(strncmp(buffer,"end",3)==0)
		{
			running=0;
		}
	}
	exit(EXIT_SUCCESS);
}

