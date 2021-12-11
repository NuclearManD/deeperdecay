//
// Created by nuclaer on 10/14/21.
//

#include <cmath>

#include <stdint.h>
#include <time.h>

// https://stackoverflow.com/questions/11765301/how-do-i-get-the-unix-timestamp-in-c-as-an-int

// Unix time, in microseconds
uint64_t micros() {
    return (uint64_t)std::round(((float)clock())/CLOCKS_PER_SEC*1000000);
}

// Unix time, in milliseconds
uint64_t millis() {
    return micros() / 1000;
}

// Unix time, in seconds as a float
double unixtime() {
    return (double)micros() / 1000000.0;
}
