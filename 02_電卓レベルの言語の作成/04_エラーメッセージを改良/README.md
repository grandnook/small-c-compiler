# ビルド
```bash
$ make
```

# 実行1
```bash
$ ./02_cc "1+3++"
```
```
1 + foo + 5
    ^ トークナイズできません
```

# 実行2
```bash
$ ./02_cc "1 + foo + 5"
```
```
.intel_syntax noprefix
.globl main
main:
    mov rax, 1
    add rax, 3
1+3++
    ^ 数ではありません
```

# 削除
```bash
$ make clean
```
