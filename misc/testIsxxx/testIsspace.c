#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    int i = 0;
    char* str = "1   +   2";
    printf("before: %s\n", str);
    printf("after : ");

    for(i=0;i<strlen(str);i++){
        if(isspace(str[i])){
            printf("_");
        }
        else{
            printf("%c", str[i]);
        }
    }
    printf("\n");

    return 0;
}
