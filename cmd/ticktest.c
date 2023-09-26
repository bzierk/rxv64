#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <procstats.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

// Test which runs arbitrary, time-consuming calculations. This can be run as a background process and the `ps` program used to monitor tick counts
// Source cited:
// https://medium.com/@harshalshree03/xv6-implementing-ps-nice-system-calls-and-priority-scheduling-b12fa10494e4


int main(int argc, char *argv[]) {

//    int pid;
//    int k, n, x;
//    uint64_t z;
//    int tickets;
//
//    if (argc < 2) {
//        n = 1;
//        tickets = 1;
//    } else {
//        n = atoi(argv[1]);
//        tickets = atoi(argv[2]);
//    }
//    if (n < 0 || n > 20)
//        n = 2;
//    if (tickets < 0)
//        tickets = 1;
//    x = 0;
//    pid = 0;
//    settickets(tickets);
//
//    for (k = 0; k < n; k++) {
//        pid = fork();
//        if (pid < 0) {
//            printf("%d failed to fork\n", getpid());
//        } else if (pid > 0) {
//            printf("Parent %d creating child %d\n", getpid(), pid);
////            wait(NULL);
//        } else {
//            printf("Child %d created\n", getpid());
//            for (z = 0; z < 40000000000; z += 1) {
//                x = x + 3 * 89;
//            }
//            printf("Child %d done\n", getpid());
//            break;
//        }
//    }
//
//    exit(0);
    int pid;
    int k;
    uint64_t z;
    int x = 0;

    int tickets[] = {100, 100, 800}; // Two processes, one with 10 tickets and the other with 90
    int n = 3; // Number of processes you want to spawn

    for (k = 0; k < n; k++) {
        pid = fork();
        if (pid < 0) {
            printf("%d failed in fork\n", getpid());
            exit(1); // Exit with an error code
        } else if (pid == 0) {
            // Child process
            settickets(tickets[k]); // Set tickets based on array values
            for (z = 0; z < 40000000000; z++) {
                x = x + 3 * 89;
            }
            printf("Child %d done\n", getpid());
            exit(0); // Exit the child process
        }
    }

    // Parent process waits for both children
//    for (k = 0; k < n; k++) {
//        wait(NULL);
//    }

    printf("Parent done\n");
    exit(0);
}