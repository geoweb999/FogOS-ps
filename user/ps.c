#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "kernel/param.h"
#include "user/user.h"

// NPROC defined in param.h
#define MAX_PROCS NPROC
#define NELEM(x) (sizeof(x)/sizeof((x)[0]))


struct proc_data {
  int  pid;
  int  ppid;
  int  state;
  int  sz;
  char name[16];
};

int main (int argc, char *argv[]) {
    // copied from procdump
    static char *states[] = {
    "unused",
    "used",
    "sleep ",
    "runble",
    "run   ",
    "zombie"
    };
    char *state;
    struct proc_data pd[MAX_PROCS];

    if(argc == 2 && strcmp(argv[1], "-h") == 0){
        printf("ps -- report process status\n");
        printf("usage: ps [-h]\n");
        printf("-h: print this helpful information\n");
        exit(0);
    } else if (argc == 2) {
        printf("Invalid parameter, ps -h for help\n");
        exit(1);
    }

    int tot = getprocs(pd, MAX_PROCS);
    if (tot < 0) {
        printf("getprocs failed\n");
        exit(1);
    }

    printf("%d processes are running\n", tot);
    printf("PID\tPPID\tSTATE\tSIZE\tNAME\n");

    int i;
    for (i = 0; i < tot; i++) {
        if(pd[i].state >= 0 && pd[i].state < NELEM(states) && states[pd[i].state]) {
            state = states[pd[i].state];
        }
        else {
            state = "???";
        }
        printf("%d\t%d\t%s\t%d\t%s\n", pd[i].pid, pd[i].ppid, state, pd[i].sz, pd[i].name);

    }
    exit(0);
}
