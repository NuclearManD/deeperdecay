//
// Created by nuclaer on 10/14/21.
//

#ifndef DEEPERDECAY_LOGGING_H
#define DEEPERDECAY_LOGGING_H

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3
#define CRITICAL 4

void log_printf(const char* fmt, int level, ...);

#endif //DEEPERDECAY_LOGGING_H
