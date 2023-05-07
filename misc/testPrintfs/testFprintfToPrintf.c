#include <stdio.h>

int main(){
    int i = 4;

    fprintf(stdout, "OK [%d]: from %s\n", i, __FILE__);

    return 0;
}
