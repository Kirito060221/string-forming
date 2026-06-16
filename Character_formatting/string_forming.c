#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024 // 文字型配列に格納できる文字の最大数
void handle_special_command(char word[], int* current_len, FILE* fp);
int main()
{
    FILE* fp;
    int line_len, i = 0, current_len;
    char fname[BUFSIZE], line_buf[BUFSIZE];

    // テキストファイル読み込み処理
    printf("整形するファイル名を入力してください：");
    scanf("%s", fname);
    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("%s ファイルを開けません\nファイルが存在するか確認してください\n", fname);
        return -1;
    }
    // １行あたりの文字数入力処理
    printf("１行あたりの文字数を入力してください：");
    scanf("%d", &line_len);

    // 01234...と目盛りを表示
    for (i = 1; i <= line_len; i++) {
        printf("%d", i % 10);
    }
    printf("\n\n");
    // ファイルの内容を１行ずつ読み出し
    while (fgets(line_buf, BUFSIZE, fp) != NULL) {
        char* word = strtok(line_buf, " \t\r\n"); // スペース区切りで格納（タブや改行にも対応）
        while (word != NULL) {
            // １行あたりの文字数を超える大きさの単語が見つかった場合の処理
            if (strlen(word) > line_len) {
                printf("\n文中の単語%sが%dを超えています(%d文字)", word, line_len, strlen(word));
                return -1;
            } else if (word[0] == '/' && word[strlen(word) - 1] == '/') {
                handle_special_command(word, &current_len, fp); // 特殊文字対応関数の呼び出し
            } else {
                // 「１行につき現在表示した文字（＋スペース）数」＋取得した単語の文字数を見る
                if (strlen(word) + current_len > line_len) {
                    printf("\n");
                    current_len = 0;
                }
                // 単語を表示し、「１行につき現在表示した文字数」に単語の文字数＋１（スペース分）足す
                printf("%s ", word);
                current_len = current_len + strlen(word) + 1;
            }
            word = strtok(NULL, " \n"); // 2個目以降はNULL（残りが自動的に指定）
        }
    }
    printf("\n\n");
    fclose(fp);
    // 01234...と目盛りを表示
    for (i = 1; i <= line_len; i++) {
        printf("%d", i % 10);
    }
    printf("\n");
    return 0;
}

// 特殊文字への対応
void handle_special_command(char word[], int* current_len, FILE* fp)
{
    if (strcmp(word, "/par/") == 0) { // 特殊文字/par/：段落の作成、１行空け６文字分スペースを空ける
        printf("\n\n      ");
        *current_len = 6;
    } else if (strcmp(word, "/break/") == 0) { // 特殊文字/break/：改行
        printf("\n");
        *current_len = 0;
    } else if (strcmp(word, "/space/") == 0) { // 特殊文字/space/：改行し、さらに１行分空ける
        printf("\n\n");
        *current_len = 0;
    }
    return;
}