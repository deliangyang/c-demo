#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>   // read(), write(), close()

#define MAX_OPEN_FD 1024
#define MAX 80
#define PORT 5000
#define SA struct sockaddr

// https://man7.org/linux/man-pages/man2/epoll_ctl.2.html
// EPOLL_CTL_ADD add
// EPOLL_CTL_MOD modify
// EPOLL_CTL_DEL del
int main(int argc, char const *argv[]) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in servaddr;
  if (sockfd == -1) {
    printf("socket created failed...\n");
    exit(0);
  } else {
    printf("socket created successfully...\n");
  }
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(5000);

  bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  listen(sockfd, 10);

  struct epoll_event tep, ep[MAX_OPEN_FD];
  int efd = epoll_create(MAX_OPEN_FD);
  tep.events = EPOLLIN;
  tep.data.fd = sockfd;
  // 把监听socket 先添加到efd中
  int ret = epoll_ctl(efd, EPOLL_CTL_ADD, sockfd, &tep);
  // ep = malloc(sizeof(struct epoll_event) * MAX_OPEN_FD);

  char sendBuff[1025];
  time_t ticks;
  int connfd = 0;
  while (1) {
    // 返回已就绪的epoll_event,-1表示阻塞,没有就绪的epoll_event,将一直等待
    printf("ready receive...\n");
    size_t nready = epoll_wait(efd, ep, MAX_OPEN_FD, -1);
    printf("ready n: %d...\n", nready);
    for (int i = 0; i < nready; i++) {
      printf("ready fd: %d, socket fd: %d...\n", ep[i].data.fd, sockfd);
      if (ep[i].data.fd == sockfd) {
        connfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        tep.events = EPOLLIN;
        tep.data.fd = connfd;
        ret = epoll_ctl(efd, EPOLL_CTL_ADD, connfd, &tep);
        if (ret == 0) {
          printf("add client fd into epoll successfully.\n");
        } else {
          printf("add client fd into epoll failed: %d.\n", ret);
        }
      } else {
        connfd = ep[i].data.fd;
        ticks = time(NULL);
        snprintf(sendBuff, sizeof(sendBuff), "%.24s, index: %d\r\n",
                 ctime(&ticks), i);
        write(connfd, sendBuff, strlen(sendBuff));
        ret = epoll_ctl(efd, EPOLL_CTL_DEL, connfd, NULL);
        printf("client[%d] closed\n", i);
        close(connfd);
      }
    }
  }
  close(sockfd);
  printf("sock closed\n");
  return 0;
}
