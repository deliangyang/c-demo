#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("received SIGINT\n");
}

int main(int argc, char const *argv[]) {
  if (signal(SIGINT, sig_handler) == SIG_ERR) {
    printf("can't catch SIGINT");
  }
  while (1) {
    sleep(1);
  }
  return 0;
}
