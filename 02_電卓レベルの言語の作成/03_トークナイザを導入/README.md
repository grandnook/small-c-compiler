# 実行
```bash
$ make test
```

# デバッグ
```bash
$ make debug
```

# 削除
```bash
$ make clean
```

# ソースコードの簡単な解説

まず，コマンドライン引数を``tokenize``したものをグローバル変数の``token``に代入する．

なお，この``token``については，main関数では直接触らず，その代わりに``consume``，``expect``，``expect_number``といった関数内でしか操作しない．これらの関数の内部では，``token``の連結リストが進むようになっている（``token = token->next;``）．
```C
int main(){
    ...
    token = tokenize(argv[1]);
    ...
```

``tokenize``関数の内部では，ダミーの``head``を作成して，それに新しい要素を繋げていって，最後に``head->next``を返すようになっている．

この仕様の理由を考察する．
グローバル変数の``token``はポインタであるため，実体がない．そこで，``tokenize``関数の内部では，実体のある``head``を用意することでその問題を回避していると思われる．
なお，変数``token``と``head``の型の違いに関しては，``head->next``が吸収してくれている．

```C
// 記号（'+', '-'）
if (*p == '+' || *p == '-'){
    current = new_token(TK_RESERVED, current, p++);
    continue;
}

// 数字文字
if (isdigit(*p)){
    current = new_token(TK_NUM, current, p);
    current->val = strtol(p, &p, 10);
    continue;
}
```

``new_token``関数の内部では，新しい要素である``tok``が作成される．``tok``には，記号か数字かの``kind``と（先頭から読み込まれて残った全部の）文字列が``str``に格納される．
- ``current->next = tok;``: ``current``に新しい要素``tok``を繋げる
- ``return tok;``: main関数の``current``は新しい要素``tok``に更新される
- トークンの先頭が数字文字の場合は，その値が更新済みの``current``の``val``に格納される

whileループ内部でのトークンの文字列のインクリメントに関しては，記号の場合は``p++``で，数字文字の場合は``strtol(p, &p, 10)``で処理される．
