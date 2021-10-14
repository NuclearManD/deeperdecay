//
// Created by nuclaer on 10/14/21.
//

#ifndef DEEPERDECAY_TIMEUTIL_H
#define DEEPERDECAY_TIMEUTIL_H

#include <stdint.h>

// Unix time, in microseconds
uint64_t micros();

// Unix time, in milliseconds
uint64_t millis();

// Unix time, in seconds as a float
double unixtime();

#endif //DEEPERDECAY_TIMEUTIL_H
