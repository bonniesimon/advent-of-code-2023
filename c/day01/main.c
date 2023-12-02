/*

PART 1

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int calculate_magic_number(char *word, size_t length);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("File not passed as argument to executable\n");
  }

  FILE *file = fopen(argv[1], "r");

  if (file == NULL) {
    printf("File cannot be opened\n");
    return 0;
  }

  char word[100];

  int sum = 0;

  while(fscanf(file, "%s", word) == 1)  {
    size_t length = strlen(word);

    sum += calculate_magic_number(word, length);
  }

  printf("%d\n", sum);

  fclose(file);

  return 0;
}


int calculate_magic_number(char *word, size_t length) {

  int first = -1;
  int last = -1;

  for (size_t i = 0; i < length; i++) {
    if (word[i] < '0' || word[i] > '9') continue;

    if (first == -1) {
      first = word[i] - '0';
      last = word[i] - '0';
    } else {
      last = word[i] - '0';
    }
  }

  return first * 10 + last;
}
