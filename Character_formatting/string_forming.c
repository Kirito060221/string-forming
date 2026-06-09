#include <stdio.h>
#include <string.h>
int main()
{
    FILE* fp;
    char str[1000];
    int n, i;

    // 01234...と表示
    for (i = 1; i < n; i++) {
        printf("%d", i % 10);
    }
    printf("\n\n");
    while (fscanf(fp, "%s", str) != EOF) {
    }
}