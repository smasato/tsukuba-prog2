#include <stdio.h>
#include <time.h>
#include "Timer.h"

time_t GetTime(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec;
}

time_t GetRapTime(time_t prevTime) {
    return GetTime() - prevTime;
}
