#include <stdio.h>
#include <stdlib.h>  // exit()などに必要
#include <stdarg.h>  // va_start()などに必要
#include <stdbool.h>  // bool型, true, falseなどに必要
#include <ctype.h>  // isspace(), isdigit()などに必要
// #include <string.h>

typedef enum {
    TK_RESERVED,    // 記号
    TK_NUM,         // 整数
    TK_EOF,         // 終端用
} TokenKind;

typedef struct Token_ {
    TokenKind kind;         // トークンの種類
    int val;                // 数字トークンの値
    char *str;              // トークン文字列
    struct Token_ *next;    // 次の入力トークン
} Token;

Token *token;  // 現在注目しているトークン

// エラー出力用の関数（printfと同じ引数を取る）
void error(char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}

// トークンが期待している記号の時は，次のトークンに進めて，trueを返す
// そうでない場合は，falseを返す
bool consume(char op){
    if (token->kind != TK_RESERVED || token->str[0] != op){
        return false;
    }

    token = token->next;

    return true;
}

// bool consume()のvoid型版でエラーを報告する
void expect(char op){
    if (token->kind != TK_RESERVED || token->str[0] != op){
        error("'%c'ではありません", op);
    }

    token = token->next;
}

// トークンが期待している数の時は，次のトークンに進めて，その数を返す
// そうでない場合は，エラーを報告する
int expect_number(){
    if (token->kind != TK_NUM){
        error("数ではありません");
    }
    int val = token->val;
    token = token->next;
    return val;
}

bool at_eof(){
    return token->kind == TK_EOF;
}

// 新しいトークンを作成して，currentに繋げる
Token *new_token(TokenKind kind, Token *current, char *str){
    Token *tok = calloc(1, sizeof(Token));
    tok->kind = kind;
    tok->str = str;
    current->next = tok;
    return tok;
}

Token *tokenize(char *p){
    Token head;
    head.next = NULL;
    Token *current = &head;

    while(*p){
        // 空白
        if (isspace(*p)){
            p++;
            continue;
        }

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

        // その他
        error("トークナイズできません");
    }

    new_token(TK_EOF, current, p);
    return head.next;
}


int main(int argc, char **argv){
    if (argc != 2){
        error("引数の個数が正しくありません");
        return 1;
    }

    token = tokenize(argv[1]);

    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("    mov rax, %d\n", expect_number());

    while(!at_eof()){
        if (consume('+')){
            printf("    add rax, %d\n", expect_number());
            continue;
        }

        expect('-');
        printf("    sub rax, %d\n", expect_number());
    }

    printf("    ret\n");
    return 0;
}
