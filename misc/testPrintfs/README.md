# printf, sprintf, fprintf, vfprintfなどの違いについて

## printf
src: ``testPrintf.c``

ターミナル上に標準出力する．

## sprintf
src: ``testSprintf.c``

文字列配列に出力する．

## fprintf
src: ``testFprintf.c``

ファイルに出力する．

## fprintfをprintfに変換する
src: ``testFprintfToPrintf.c``

``fprintf``の出力先を標準出力``stdout``に変更すると，``printf``と同じ挙動となる．

## vfprintf
src: ``testVfprintf_v1.c``

### 必要なヘッダファイル
``#include <stdarg.h>``

### ソースコードの簡単な説明

``va_start``を利用することで，可変長引数を``va_list ap``でアクセスできるようにする．

なお，可変長引数とは，``printf``の定義では，``...``に相当する部分，つまり，通常は引数として変数を渡す部分のことである．

また，``va_list ap``で受け取った可変長引数は，``vfprintf``を利用して出力することになる．

```C
#include <stdio.h>
int printf(const char *format, ...);
```

その後は，標準エラー出力に向けて，文字列と改行文字を出力して，（``exit(1)``で）終了する．

> ``exit(1)``があると異常終了となるため，``Makefile``はエラー文を出力して停止する．

# vfprintf (advanced)
src: ``testVfprintf_v2.c``

``va_list ap``で受け取った可変長引数は，``vfprintf``で出力するということを分かりやすくしたサンプルコードである．

文字列の指定した位置（``pos``）に``^``を出力することで，エラーの場所が何バイト目か分かるような使い方ができる．

``vfprintf``関数の前後に，``fprintf``関数などを入れることで，ラッパーのような実装となっている．

```C
printf("%*s", 3, "")
```
の``%*s``とは，``*``が文字数を表しており，今回は第二引数で**最低**3文字を指定している．

```C
printf("%.*s", 3, "")
```
のように``.``を追加すると，**最大**3文字までとなる．

この仕様を利用することで，``^``前のスペースの文字列を実現している．


# 実行と削除
```bash
$ make
```
```
cc     testPrintf.c   -o testPrintf
cc     testSprintf.c   -o testSprintf
cc     testFprintf.c   -o testFprintf
cc     testFprintfToPrintf.c   -o testFprintfToPrintf
cc     testVfprintf_v1.c   -o testVfprintf_v1
cc     testVfprintf_v2.c   -o testVfprintf_v2
./testPrintf
OK [1]: from testPrintf.c
./testSprintf
OK [2]: from testSprintf.c
./testFprintf
cat tmp.txt
OK [3]: from testFprintf.c
./testFprintfToPrintf
OK [4]: from testFprintfToPrintf.c
./testVfprintf_v1
Error [5]: from testVfprintf_v1.c
./testVfprintf_v2
-----
"   "
"   "
-----

pos = 3
abcde
   ^ Error [6]: from testVfprintf_v2.c
```
```bash
$ make clean
```
```
rm -f testPrintf testSprintf testFprintf tmp.txt testFprintfToPrintf testVfprintf_v1 testVfprintf_v2
```
