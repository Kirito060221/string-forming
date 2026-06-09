#include <stdio.h>
#include <string.h>
int main()
{
    FILE* fp;
    char fname[] = "input.txt";
    char chr;
    int i=0;

    fp = fopen(fname, "r");
    if(fp == NULL) {
        printf("%s file not open!\n", fname);
        return -1;
    }

    while((chr = fgrtc(fp)) != EOF) {
        putchar(chr);
    }

    fclose(fp);

    return 0;
}