#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024

int handle_special_command(char word[], int* current_len, FILE* fp);

int main()
{
    FILE* fp;
    char word[BUFSIZE];
    int n, i = 0, current_len;
    char fname[BUFSIZE];
    char chr;
    printf("整形するファイル名を入力してください：");
    scanf("%s", fname);
    printf("１行あたりの文字数を入力してください");
    scanf("%d", n);

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("%s file not open!\n", fname);
        return -1;
    }
    /*
        while((chr = fgrtc(fp)) != EOF) {
            putchar(chr);
        }
    */

    // 01234...と表示
    for (i = 1; i < n; i++) {
        printf("%d", i % 10);
    }
    printf("\n\n");
    while (fscanf(fp, "%s", word) != EOF) {
        if (word[0] == '/' && word[strlen(word) - 1 == '/']) {
            handle_special_command(word, &current_len, fp);
        } else {
            // 入れていい文字と入れる文字数の比較
            if (strlen(word) + current_len > n) {
                printf("\n");
                current_len = 0;
            }
            printf("%s ", word);
            current_len = current_len + strlen(word) + 1;
            // printf("(%d)", n);
        }
    }
    printf("\n\n");
    fclose(fp);
    for (i = 1; i < n; i++) {
        printf("%d", i % 10);
    }

    return 0;
}

int handle_special_command(char word[], int* current_len, FILE* fp)
{
    if (strcmp(word, "/par/") == 0) {
        printf("\n\n      ");
        *current_len = 6;
        return 1;
    } else if (strcmp(word, "/break/") == 0) {
        printf("\n");
        *current_len = 0;
        return 1;
    } else if (strcmp(word, "/space/") == 0) {
        printf("\n\n");
        *current_len = 0;
        return 1;
    }
    return 0;
}