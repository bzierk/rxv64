//
// Created by bryan on 9/10/23.
//
#include <stdio.h>
#include <procstats.h>

int main(int argc, char *argv[]) {
    ProcStats stats;

    if (getpinfo(&stats) < 0) {
        printf("Error: get_processes() failed\n");
        return -1;
    }

    printf("PID\tTickets\tHi\tLo\n");
    for (int i = 0; i < NPROC; i++) {
        if (stats.in_use[i] == 1) {
            printf("%d\t%d\t%d\t%d\n", stats.pid[i], stats.tickets[i], stats.hi_ticks[i], stats.lo_ticks[i]);
        }
    }

    return 0;

}
