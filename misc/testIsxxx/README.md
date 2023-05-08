# 文字の種類を判別する関数

# 実行と削除
```bash
$ make
```
```bash
$ make clean
```

# isspace
src: ``testIsspace.c``

空白文字を判別する．

以下は，空白をアンダーバーに変換する簡単なプログラムの略例．

```C
char* str = "1   +   2";

for(i=0;i<strlen(str);i++){
    if(isspace(str[i])){
        printf("_");
    }
    else{
        printf("%c", str[i]);
    }
}
```

```
before: 1   +   2
after : 1___+___2
```


# isdigit
src: ``testIsdigit.c``

``0``~``9``までの数字文字を判別する．

以下は，数字文字を``X``に変換するのと，数字は判別できるのかをチェックする簡単なプログラムの略例．

```C
char* str = "1   +   2";
for(i=0;i<strlen(str);i++){
    if(isdigit(str[i])){
        printf("X");
    }
    else{
        printf("%c", str[i]);
    }
}

int number = 1;
if(isdigit(number)){
    printf("OK: int type is allowed.\n");
}else{
    printf("NG: int type is not allowed.\n");
}
```

```
before: 1   +   2
after : X   +   X
NG: int type is not allowed.
```