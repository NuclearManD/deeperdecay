//
// Created by nuclaer on 10/19/21.
//

#include <stdbool.h>
#include <string.h>


// https://stackoverflow.com/questions/744766/how-to-compare-ends-of-strings-in-c
bool strendswith(const char* s, const char* e) {
    size_t slen = strlen(s);
    size_t sufflen = strlen(e);

    return slen >= sufflen && !memcmp(s + slen - sufflen, e, sufflen);
}
