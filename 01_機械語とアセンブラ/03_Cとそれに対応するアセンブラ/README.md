# C言語のソースコード「.c」をコンパイル
```bash
gcc simple_example.c  // コンパイル
./a.out  // 実行
echo $?  // 終了ステータスを見ると「42」であり，./a.outの実行結果が反映されている
echo $?  // 終了ステータスを見ると「0」であり，直前のechoが正常終了したと分かる
```

# アセンブリのソースコード「.s」をコンパイル
```bash
cc simple_example.s  // コンパイル
./a.out  // 実行
echo $?  // 終了ステータスを見ると「42」であり，./a.outの実行結果が反映されている
echo $?  // 終了ステータスを見ると「0」であり，直前のechoが正常終了したと分かる
```

# アセンブリのソースコードの解説
src: simple_example.s

1. 42をRAXにセットする
2. 関数からリターンしたときに，RAXに入っている値が関数の返り値になる

```Assembly
.intel_syntax noprefix
.globl main
main:
        mov rax, 42
        ret
```

# C言語のソースコード「.c」をコンパイル
```bash
gcc with_function.c  // コンパイル
./a.out  // 実行
echo $?  // 終了ステータスを見ると「7」であり，./a.outの実行結果が反映されている
echo $?  // 終了ステータスを見ると「0」であり，直前のechoが正常終了したと分かる
```

# アセンブリのソースコード「.s」をコンパイル
```bash
cc with_function.s  // コンパイル
./a.out  // 実行
echo $?  // 終了ステータスを見ると「7」であり，./a.outの実行結果が反映されている
echo $?  // 終了ステータスを見ると「0」であり，直前のechoが正常終了したと分かる
```

# アセンブリのソースコードの解説
src: with_function.s

```Assembly
.intel_syntax noprefix
.globl plus, main

plus:
        add rsi, rdi
        mov rax, rsi
        ret

main:
        mov rdi, 3
        mov rsi, 4
        call plus
        ret
```

1. 1行目は，Intel記法のアセンブリの文法を指定する命令
2. 2行目は，plusとmainという2つの関数がファイルスコープではなくプログラム全体から見える関数だということをアセンブリに指示
3. main関数を見る
4. 第一引数はRDIレジスタ，第二引数はRSIレジスタにセット
5. callは関数を呼び出す命令
    - callの次の命令（この場合ret）のアドレスをスタックにプッシュ
    - callの引数として与えられたアドレスにジャンプ（つまり，plus関数を実行し始める）
6. plus関数に移動
7. RSIレジスタとRDIレジスタの和をRSIレジスタにセット（第1引数が上書きされる）
8. RAXレジスタに演算結果をセットして，リターンする．retの働きは主に以下の通り
    - スタックからアドレスを1つポップ
    - そのアドレスにジャンプ（つまり，mainのret）
9. 演算結果はRAXレジスタに入ったままなので，mainのretが呼ばれると，そのままmainの返り値が演算結果となる

> 関数呼び出しはスタックを使って実装されている