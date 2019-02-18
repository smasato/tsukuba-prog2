//
// lib/Timer.c
//

#include <stdio.h>
#include <time.h>
#include "Timer.h"

time_t getTime(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec;
}

time_t getRapTime(time_t prevTime) {
    return getTime() - prevTime;
}
