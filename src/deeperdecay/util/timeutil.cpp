//
// Created by nuclaer on 10/14/21.
//

#include <stdint.h>
#include <time.h>

// https://stackoverflow.com/questions/11765301/how-do-i-get-the-unix-timestamp-in-c-as-an-int

// Unix time, in microseconds
uint64_t micros() {
    struct timespec tms;

    // Use C++11 timespec_get if available, or clock_gettime otherwise.
#if __cplusplus >= 201103L
    if (! timespec_get(&tms, TIME_UTC)) {
#else
    if (clock_gettime(CLOCK_REALTIME,&tms)) {
#endif
        return -1;
    }

    /* seconds, multiplied with 1 million */
    int64_t micros = tms.tv_sec * 1000000;

    /* Add full microseconds */
    micros += tms.tv_nsec/1000;

    // Commented out the round up, we don't need to be exact and this
    // wastes CPU cycles.
    /*if (tms.tv_nsec % 1000 >= 500) {
        ++micros;
    }*/
    return micros;
}

// Unix time, in milliseconds
uint64_t millis() {
    return micros() / 1000;
}

// Unix time, in seconds as a float
double unixtime() {
    return (double)micros() / 1000000.0;
}
