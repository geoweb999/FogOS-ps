#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

#define MAX_PROCS 64

struct proc_data {
  int  pid;
  int  ppid;
  int  state;
  int  sz;
  char name[16];
};

int main (int argc, int **argv) {
    struct proc_data pd[MAX_PROCS];

    int tot = getprocs(pd, MAX_PROCS);
    if (tot < 0) {
        printf("getprocs failed\n");
        exit(1);
    }

    printf("%d processes are running\n", tot);
    exit(0);
}
