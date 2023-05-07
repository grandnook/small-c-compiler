# 01_Makefile
src: ``01_Makefile``

``Makefile``と``make``コマンドの基本的な使い方について．

次のような``01_Makefile``を用意した．

``x``，``a``，``b``，``c``の4つのターゲット（ルール）を記述している．

```Makefile
x:
	echo "xxx"
a: c b
	echo "aaa"
b:
	echo "bbb"
c:
	echo "ccc"
```

``make``コマンドを利用すると，デフォルトで``Makefile``の1番上のルールが適応される．

```bash
$ make -f 01_Makefile
```
```
echo "xxx"
xxx
```

しかし，ターゲット名を指定すると，そのルールが適応される．
なお，ターゲット名の場所はオプションの前後どちらでも可能だった．

```bash
$ make a -f 01_Makefil
```
```bash
$ make -f 01_Makefil a
```
```
echo "ccc"
ccc
echo "bbb"
bbb
echo "aaa"
aaa
```


# 02_Makefile
src: ``02_Makefile``

変数の扱い方について．

次のような``02_Makefile``を用意した．

``CC``とは（おそらく）``C Compiler``の略称だと思われる．

```Makefile
CC=gcc12345

x:
	echo "xxx $(CC)"
```

``$(CC)``のように，``$``と``()``で囲むことで参照できる．

実行する．

```bash
$ make -f 02_Makefile
```
```
echo "xxx gcc12345"
xxx gcc12345
```


# 03_Makefile
src: ``03_Makefile``, ``phonyDir``

フォニーターゲット（ダミーターゲット）について．

次のような``03_Makefile``を用意した．

``phonyDir``というターゲットと，``.PHONY``ターゲットを記述している．

```Makefile
phonyDir:
	echo "phonyDir"
.PHONY: phonyDir
```

また，次のように，フォニーターゲットと同じ名前のディレクトリを同階層に作成した．

```bash
.
├── 03_Makefile
└── phonyDir/
```

このように，ターゲット名とディレクトリ名が同じ場合に，``.PHONY``がないとターゲットの方が認識されなくて困る．

実際に，``03_Makefile``において，3行目の``.PHONY``をコメントアウトしたりしなかったりすることで，ある場合とない場合の2パターンを実行する．

```bash
$ make -f 03_Makefile
```

1. ``.PHONY``がない場合の実行結果（失敗）．
```
make: 'phonyDir' is up to date.
```

2. ``.PHONY``がある場合の実行結果（成功）．
```
echo "phonyDir"
phonyDir
```

# 04_Makefile
src: ``04_Makefile``, ``04_main.c``

次のような``04_Makefile``を用意した．

```Makefile
04_main: 04_main.c

test: 04_main
	./04_main

clean:
	rm -f 04_main

.PHONY: test clean
```

1行目の``04_main: 04_main.c``について解説する．
``.c``のファイル名と同じ名前のターゲットを用意すると，自動的にその名前の実行ファイルが生成される．
ルールの中身は何も書いていないが，``make``の暗黙のルールにより``cc``コンパイラによって自動的にコンパイルされる（``cc 04_main.c -o 04_main``）．
今回の生成物は，実行ファイルの``04_main``である．

また，``make test``で実行が，``make clean``で削除が行われる．



実行する．

```bash
$ make -f 04_Makefile test
```
```
cc     04_main.c   -o 04_main
./04_main
OK: 04_main.c from 04_Makefile
```

不要なファイルを削除する．
```bash
$ make -f 04_Makefile clean
```
```
rm -f 04_main
```




# 05_Makefile
src: ``05_Makefile``, ``05_main.c``

``CFLAGS``を使用すると，``cc``コンパイラにオプションを付与することができる（``cc -std=c11 -g -static 05_main.c -o 05_main``）．

```Makefile
CFLAGS=-std=c11 -g -static
SRC=05_main

$(SRC): $(SRC).c

test: $(SRC)
	./$(SRC)

clean:
	rm -f $(SRC)

.PHONY: test clean
```

実行する．

```bash
$ make -f 05_Makefile test
```
```
cc -std=c11 -g -static    05_main.c   -o 05_main
./05_main
OK: 05_main.c from 05_Makefile
```

不要なファイルを削除する．
```bash
$ make -f 05_Makefile clean
```
```
rm -f 05_main
```

