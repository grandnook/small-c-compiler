#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    int i = 0;
    char* str = "1   +   2";
    printf("before: %s\n", str);
    printf("after : ");

    for(i=0;i<strlen(str);i++){
        if(isdigit(str[i])){
            printf("X");
        }
        else{
            printf("%c", str[i]);
        }
    }
    printf("\n");

    int number = 1;
    if(isdigit(number)){
        printf("OK: int type is allowed.\n");
    }else{
        printf("NG: int type is not allowed.\n");
    }

    return 0;
}
