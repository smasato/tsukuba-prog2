#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "Timer.h"

static struct timespec ts;

void StartTimer(void) {
    clock_gettime(CLOCK_MONOTONIC, &ts);
}

time_t GetTime(void) {
    struct timespec newTs;
    clock_gettime(CLOCK_MONOTONIC, &newTs);

    return newTs.tv_sec - ts.tv_sec;
}

time_t GetRapTime(time_t prevTime) {
    return GetTime() - prevTime;
}
