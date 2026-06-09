#include <stdio.h>
#include <string.h>

int handle_special_command(char word[], int *current_len, FILE *fp);

int main()
{
    FILE* fp;
    char str[1000];
    int n, i=0;
    char fname[];
    char chr;

    fp = fopen(fname, "r");
    if(fp == NULL) {
        printf("%s file not open!\n", fname);
        return -1;
    }
/*
    while((chr = fgrtc(fp)) != EOF) {
        putchar(chr);
    }
*/
    fclose(fp);
  
    // 01234...と表示
    for (i = 1; i < n; i++) {
        printf("%d", i % 10);
    }
    printf("\n\n");
    while (fscanf(fp, "%s", str) != EOF) {
    }

    return 0;
}

int handle_special_command(char word[], int *current_len, FILE *fp)
{
  if (strcmp(word, "/par/") == 0)
  {
    printf("\n\n      ");
    *current_len = 6;
    return 1;
  }
  else if (strcmp(word, "/break/") == 0)
  {
    printf("\n");
    *current_len = 0;
    return 1;
  }
  else if (strcmp(word, "/space/") == 0)
  {
    printf("\n\n");
    *current_len = 0;
    return 1;
  }
  return 0;   
}