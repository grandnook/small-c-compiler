#include <stdio.h>

int main(){
    int i = 3;
    FILE* fp;

    fp = fopen("tmp.txt", "w");

    fprintf(fp, "OK [%d]: from %s\n", i, __FILE__);

    fclose(fp);
    return 0;
}
