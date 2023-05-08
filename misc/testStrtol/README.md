# 実行と削除
```bash
$ make
```
```bash
$ make clean
```

# atoiとstrtol
src: ``testStrtol.c``

## atoi
``ascii``から``integer``に変換する関数であり，引数に与えられた数字文字を数字に変換する．

どうやら，先頭がスペースの場合のみ無視することができて，読み取り可能な部分まで数字文字を読み込み，``int``型に変換している．

数字文字でない部分は読み込まない．

負の数は読み込む．

先頭が（スペース始まりの）数字文字でない場合は，0を返した．

```C
printf("%d\n", atoi("123"));
printf("%d\n", atoi(" 456 789"));
printf("%d\n", atoi(" -1 + 2 "));
printf("%d\n", atoi("-1+2"));
printf("%d\n", atoi("_1+2"));
```
```
123
456
-1
-1
0
```

## strtol

``strtol``の様式は以下の通りである．
```C
#include <stdlib.h>
long strtol(const char *__str, char **__endptr, int __base);
```

第一引数に与えた数字文字を``long``型の数字に変換する．

変換する際の基数は第三引数で指定する．通常は10進数で読み取るので，10を与える．

与えた文字列が数字文字でない場合に読み取り失敗した際に，その場所を第二引数に与えたポインタのアドレスに格納する．

これは，数字文字を可能な限り読み取り続けた後に，インクリメントするような挙動を実装する際に役立つ．

```C
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
```
```
3
" + 5 "

0
" _3 + 5 "

before: "5 + 6"
after : " + 6", val=5
```

