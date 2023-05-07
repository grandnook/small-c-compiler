#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void error(const char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}

int main(){
    int i = 5;
    error("Error [%d]: from %s", i, __FILE__);
    return 0;
}
