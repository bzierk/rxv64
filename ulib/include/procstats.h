//
// Created by bryan on 9/11/23.
//

#ifndef RXV64_PROCSTATS_H
#define RXV64_PROCSTATS_H

#include <stdint.h>

#define NPROC 256 // Corresponds to the maximum number of processes defined at `param::NPROC`

typedef struct {
    uint32_t in_use[NPROC]; // 1 if the process is in use; 0 otherwise
    uint32_t pid[NPROC]; // Process ID
    uint32_t tickets[NPROC]; // Number of tickets assigned to the process
    uint32_t hi_ticks[NPROC]; // High-priority  ticks the process has accumulated
    uint32_t lo_ticks[NPROC]; // Low-priority ticks the process has accumulated
} ProcStats;

int getpinfo(ProcStats *stats);

int settickets(int tickets);

#endif //RXV64_PROCSTATS_H
