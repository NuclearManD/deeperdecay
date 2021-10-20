
// CLion will complain about including "deprecated" headers, but
// personally I hardly consider the modern headers as standard.
// I ALWAYS use C headers if I can.  File descriptors all the way.
#include <stdarg.h>
#include <stdio.h>

#include "timeutil.h"


/*
 * LOG LEVELS:
 *  0: Debug
 *  1: Info
 *  2: Warning  (Something that maybe is odd or shouldn't happen)
 *  3: Error    (Recoverable error)
 *  4: Critical (Irrecoverable error)
*/

// Any message with this level or higher will be output to
// the console and/or log file.
// Ignores debug messages by default.
static int log_level = 1;

// File descriptor to send logged messages to.  This will probably
// be changed to a Stream object of some kind later on.
// Assigned to STDOUT by default.
static int log_fd = 1;

static const char* log_level_to_cstr(int level) {
    switch (level) {
        case 0:
            return "DEBUG";
        case 1:
            return "INFO";
        case 2:
            return "WARNING";
        case 3:
            return "ERROR";
        case 4:
            return "CRITICAL";
        default:
            return "UNKNOWN";
    }
}


void log_vprintf(const char* fmt, int level, va_list argv) {
    if (level >= log_level) {
        // Only print something if the log level is high enough

        // This will print the unix time, then the log level in brackets (as a string)
        dprintf(log_fd, " %.3f [%.8s] ", unixtime(), log_level_to_cstr(level));

        // Print the formatted message
        vdprintf(log_fd, fmt, argv);

        // Finish with a newline
        printf("\n");
    }
}


void log_printf(const char* fmt, int level, ...) {
    // This function can accept as many arguments as you give it after the first two.
    // These two lines extract the arguments for us.
    va_list argv;
    va_start(argv, level);
    log_vprintf(fmt, level, argv);
}

