#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *user_input = "abcde";

void error(const char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    // exit(1);
}

void error_at(char *loc, char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);

    int pos = loc - user_input;
    printf("pos = %d\n", pos);
    fprintf(stderr, "%s\n", user_input);
    fprintf(stderr, "%*s", pos, "");
    fprintf(stderr, "^ ");

    vfprintf(stderr, fmt, ap);  // 引数「char *fmt」と引数「...」に相当する部分が出力
    fprintf(stderr, "\n");
    // exit(1);
}

int main(){
    int i = 6;

    printf("-----\n");
    printf("\"%*s\"\n", 3, "");
    printf("\"%*s\"\n", 3, " ");
    printf("-----\n\n");

    // error("Error [%d]: from %s", i, __FILE__);
    error_at(&user_input[3], "Error [%d]: from %s", i, __FILE__);
    return 0;
}
