/*************************************************************************
	> File Name: client_recv.c
	> Author: zhaojiayi 
	> Mail: jiayiz2019@163.com 
	> Created Time: Fri 10 Jul 2020 06:20:02 PM CST
 ************************************************************************/

#include"head.h"
extern int sockfd;

void *do_recv(void *arg) {
    while(1) {
        struct ChatMsg msg;
        bzero(&msg, sizeof(msg));
        int ret = recv(sockfd, (void *)&msg, sizeof(msg), 0);
        //printf("**%d\t%s",ret,msg.name);
        if(msg.type & CHAT_WALL) {
            printf(BLUE"%s"NONE": %s\n", msg.name, msg.msg);
        }else if (msg.type & CHAT_SYS){
            printf(YELLOW"Server Info"NONE": %s\n",msg.msg);
        } else if (msg.type & CHAT_FIN) {
            printf(L_RED"Server Info"NONE"Sever Down!\n");
            exit(1);
        } else if (msg.type & CHAT_FUNC) {
            printf(GREEN"Online List\n"NONE"%s\n",msg.name);
        }
    }
} 

