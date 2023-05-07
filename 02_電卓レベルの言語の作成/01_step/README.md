# 01_simple.s
実行例とその結果
```bash
$ cc 01_simple.s
$ ./a.out
$ echo $?
```
```
42
```

# 02_simple_cc.c
実行例とその結果
```bash
$ gcc 02_simple_cc.c
$ ./a.out 123 > tmp.s
$ gcc tmp.s
$ ./a.out
$ echo $?
```
```
123
```


# Makefile

``Makefile``の解説については，``/misc/testMakefile``を参照．

```bash
$ make test
```
```
cc -std=c11 -g -static    02_simple_cc.c   -o 02_simple_cc
bash test.sh
0 => 0
42 => 42
OK
```

```bash
$ make clean
```
```
rm -f 02_simple_cc tmp*
```


# Intel記法とAT&T記法

Intel記法の他に，AT&T記法というアセンブラの記法もUnixを中心に広く使われている．

||Intel記法|AT&T記法|
|---|---|---|
|結果レジスタ|第一引数|第二引数|
|レジスタ名|rax|%rax|
|数値|42|$42|
|式|[ ]|( )|

以下は，対比のためのいくつかの例．

```Assembly
mov rbp, rsp   // Intel
mov %rsp, %rbp // AT&T

mov rax, 8     // Intel
mov $8, %rax   // AT&T

mov [rbp + rcx * 4 - 8], rax // Intel
mov %rax, -8(rbp, rcx, 4)    // AT&T
```
