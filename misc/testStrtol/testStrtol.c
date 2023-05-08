#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("%d\n", atoi("123"));
    printf("%d\n", atoi(" 456 789"));
    printf("%d\n", atoi(" -1 + 2 "));
    printf("%d\n", atoi("-1+2"));
    printf("%d\n", atoi("_1+2"));
    printf("\n");

    char* p;
    printf("%ld\n", strtol(" 3 + 5 ", &p, 10));
    printf("\"%s\"\n", p);
    printf("\n");

    printf("%ld\n", strtol(" _3 + 5 ", &p, 10));
    printf("\"%s\"\n", p);
    printf("\n");

    char* str = "5 + 6";
    printf("before: \"%s\"\n", str);
    long val = strtol(str, &str, 10);
    printf("after : \"%s\", val=%ld\n", str, val);

    return 0;
}
