# PS(1) User Commands PS(1)

## NAME
ps - report process status

## SYNOPSIS
```
ps [-h]
```

## DESCRIPTION
The `ps` utility displays information about active processes in the system. Without any options, it shows a list of all processes including their PID, PPID, state, size, and name.

## OPTIONS
-h
: Display help information and exit.

## OUTPUT
The `ps` command displays the following information for each process:

PID
: The process ID.

PPID
: The parent process ID.

STATE
: The current state of the process. Possible states are:
  - unused: Process slot is not in use
  - used: Process is allocated but not fully initialized
  - sleep: Process is sleeping
  - runble: Process is ready to run
  - run: Process is currently running
  - zombie: Process has terminated but not yet been cleaned up

SIZE
: The size of the process memory in bytes.

NAME
: The name of the process.

## EXIT STATUS
The `ps` utility exits 0 on success, and 1 if an error occurs.

## EXAMPLES
To display information about all processes:
```
$ ps
```

To display help information:
```
$ ps -h
```

## NOTES
- The `ps` command relies on the `getprocs` system call to retrieve process information.
- The maximum number of processes that can be displayed is limited by the `NPROC` constant defined in the system.

## SEE ALSO
getprocs(2), fork(2), exec(2)

## BUGS
If an invalid state is encountered, it will be displayed as "???".
