#include <stdio.h>
#include <string.h>

int handle_special_command(char word[], int *current_len, FILE *fp);

int main()
{
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