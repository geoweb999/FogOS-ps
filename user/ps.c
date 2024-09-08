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
    printf("PID\tPPID\tSTATE\tSIZE\tNAME\n");

    int i;
    for (i = 0; i < tot; i++) {
        printf("%d\t%d\t%d\t%d\t%s\n",pd[i].pid, pd[i].ppid, pd[i].state,pd[i].sz, pd[i].name);
    }
    exit(0);
}
