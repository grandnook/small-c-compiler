# 01_tmp.s

``5 + 20 - 4``をアセンブリで実装する

```bash
$ cc -o 01_tmp 01_tmp.s
$ ./01_tmp
$ echo $?
```
```
21
```

# 02_cc.c

コマンドライン引数に``5+20-4``を与えると，``01_tmp.s``のようなアセンブリファイルを生成する．

```bash
$ make test
```
```
cc -std=c11 -g -static    02_cc.c   -o 02_cc
bash test.sh
5+20-4 => 21
OK
```
```bash
$ make clean
```
```
rm -f 02_cc tmp*
```

## strtol()

[文字列をlong値に変換（エラー検出、基数指定あり）](http://www9.plala.or.jp/sgwr-t/lib/strtol.html)

```C
#include <stdlib.h>
long strtol(const char *s, char **endptr, int base);
```

文字列 s を、baseで指定された基数でlong型に変換し返却します。このとき、文字列中に変換不可能な文字があった場合には、その文字列のポインタをendptrに格納します。
atol関数は、単に文字列を10進のlong型変数に変換するのみで、文字列中に変換不可能な文字があったときには対応できませんが、strtolを使うと、変換可能な部分についてはきちんと変換し、変換不可能な部分についても情報を得ることができます。更に、baseを指定することにより、好きな基数で変換することができます。
