#include <stdio.h>

int main(){
    int i = 2;
    char str[32];

    sprintf(str, "OK [%d]: from %s\n", i, __FILE__);

    printf("%s", str);
    return 0;
}
