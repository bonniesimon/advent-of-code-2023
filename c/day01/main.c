/*

This is part 2 solution.

For part 1 solution:
https://github.com/bonniesimon/advent-of-code-2023/blob/597c5fb54c63fb0c9e262431c333529e4a64746c/c/day01/main.c

*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_magic_number(char *word, size_t length);
int match(char character, char *word);

typedef struct {
  char *string;
  int number;
} lookup_table;

lookup_table number_table[] = {{"one", 1},   {"two", 2},   {"three", 3},
                               {"four", 4},  {"five", 5},  {"six", 6},
                               {"seven", 7}, {"eight", 8}, {"nine", 9}};

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

  while (fscanf(file, "%s", word) == 1) {
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
    int value = match(word[i], &word[i]);

    if (-1 == value) continue;

    if (first == -1) {
      first = value;
      last = value;
    } else {
      last = value;
    }
  }

  return first * 10 + last;
}

int match(char character, char *word) {
  if (character >= '0' && character <= '9') {
    return character - '0';
  }

  for (int i = 0; i < 9; i++) {
    char *found = strstr(word, number_table[i].string);

    if (found == word) {
      return number_table[i].number;
    }
  }

  return -1;
}
