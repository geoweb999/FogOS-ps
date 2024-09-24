# GETPROCS(2) System Calls Manual GETPROCS(2)

## NAME
getprocs - get information about active processes

## SYNOPSIS
```c
#include <user.h>

int getprocs(struct proc_data *pd, int max);
```

## DESCRIPTION
The `getprocs()` function retrieves information about currently active processes in the system. It populates an array of `struct proc_data` structures with details about each process, up to a maximum number specified by the caller.

The `struct proc_data` is defined as follows:

```c
struct proc_data {
    int  pid;    /* Process ID */
    int  ppid;   /* Parent process ID */
    int  state;  /* Process state */
    int  sz;     /* Size of process memory */
    char name[16]; /* Name of the process */
};
```

The function takes two arguments:
- `pd`: A pointer to an array of `struct proc_data` where the process information will be stored.
- `max`: The maximum number of processes to retrieve information for up to NPROC processes

## RETURN VALUE
On success, `getprocs()` returns the number of processes for which information was retrieved. This number is less than or equal to `max`.

On error, -1 is returned.

## ERRORS
The `getprocs()` function will fail if:
- `pd` is NULL.
- `max` is less than or equal to 0.

## NOTES
- If `max` is greater than `NPROC` (the maximum number of processes in the system), it will be capped at `NPROC`.
- The function only retrieves information for processes that are not in the `UNUSED` state.
- The `ppid` field will be 0 if the process has no parent (i.e., for the init process).
- The process name is safely copied and null-terminated.

## EXAMPLE
```c
#include <user.h>

#define MAX_PROCS 64

int main() {
    struct proc_data pd[MAX_PROCS];
    int count = getprocs(pd, MAX_PROCS);
    
    if (count == -1) {
        printf("Error calling getprocs\n");
        exit(1);
    }
    
    for (int i = 0; i < count; i++) {
        printf("PID: %d, PPID: %d, Name: %s\n", pd[i].pid, pd[i].ppid, pd[i].name);
    }
    
    exit(0);
}
```

## SEE ALSO
fork(2), exec(2), wait(2), exit(2)
