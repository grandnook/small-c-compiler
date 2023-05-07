# printf, sprintf, fprintf, vfprintfなどの違いについて

## printf
ターミナル上に標準出力する．

## sprintf
文字列配列に出力する．

## fprintf
ファイルに出力する．

## fprintfをprintfに変換する
``fprintf``の出力先を標準出力``stdout``に変更すると，``printf``と同じ挙動となる．

## vfprintf

### 必要なヘッダファイル
``#include <stdarg.h>``

### ソースコードの簡単な説明

``va_start``を利用することで，可変長引数を``va_list ap``でアクセスできるようにする．

なお，可変長引数とは，``printf``の定義では，``...``に相当する部分，つまり，通常は引数として変数を渡す部分のことである．

```C
#include <stdio.h>
int printf(const char *format, ...);
```

その後は，標準エラー出力に向けて，文字列と改行文字を出力して，``exit(1)``で終了する．

> 異常終了となるため，``Makefile``はエラー文を出力することになる．


# 実行と削除
```bash
$ make
```
```
cc     testPrintf.c   -o testPrintf
cc     testSprintf.c   -o testSprintf
cc     testFprintf.c   -o testFprintf
cc     testFprintfToPrintf.c   -o testFprintfToPrintf
cc     testVfprintf.c   -o testVfprintf
./testPrintf
OK [1]: from testPrintf.c
./testSprintf
OK [2]: from testSprintf.c
./testFprintf
cat tmp.txt
OK [3]: from testFprintf.c
./testFprintfToPrintf
OK [4]: from testFprintfToPrintf.c
./testVfprintf
Error [5]: from testVfprintf.c
make: *** [Makefile:13: test] Error 1
```
```bash
$ make clean
```
```
rm -f testPrintf testSprintf testFprintf tmp.txt testFprintfToPrintf testVfprintf
```
