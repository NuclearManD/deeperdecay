//
// Created by nuclaer on 10/14/21.
//

#ifndef DEEPERDECAY_LOGGING_H
#define DEEPERDECAY_LOGGING_H

#include <stdarg.h>

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3
#define CRITICAL 4

void log_printf(const char* fmt, int level, ...);
void log_vprintf(const char* fmt, int level, va_list args);

inline void log_debug(const char* fmt, ...) {
    va_list argv;
    va_start(argv, fmt);
    log_vprintf(fmt, DEBUG, argv);
}
inline void log_info(const char* fmt, ...) {
    va_list argv;
    va_start(argv, fmt);
    log_vprintf(fmt, INFO, argv);
}
inline void log_warning(const char* fmt, ...) {
    va_list argv;
    va_start(argv, fmt);
    log_vprintf(fmt, WARNING, argv);
}
inline void log_error(const char* fmt, ...) {
    va_list argv;
    va_start(argv, fmt);
    log_vprintf(fmt, ERROR, argv);
}
inline void log_critical(const char* fmt, ...) {
    va_list argv;
    va_start(argv, fmt);
    log_vprintf(fmt, CRITICAL, argv);
}

#endif //DEEPERDECAY_LOGGING_H
