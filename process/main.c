
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  /* code */
  pid_t child, p;
  int status;

  child = fork();
  if (child == (pid_t)-1) {
    return 1;
  } else if (!child) {
    printf("new process: %d\n", child);
    execlp("/bin/ls",  "ls", "-lA", NULL);
    sleep(100);
    printf("new process: %d\n", child);
    return 127;
  }

  do {
    status = 0;
    p = waitpid(child, &status, 0);
    if (p == (pid_t)-1 && errno != EINTR) {
      break;
    }
  } while (p != child);
  if (p != child) {
    printf("p != child");
  } else if (WIFEXITED(status)) {
    printf("WIFEXITED\n");
  } else if (WIFSIGNALED(status)) {
    printf("WIFSIGNALED\n");
  } else {
    printf("else\n");
  }
  return 0;
}
