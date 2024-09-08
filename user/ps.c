#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main (int argc, int **argv) {
    int tot = getprocs();
    printf("%d processes are running\n", tot);
    exit(0);
}
