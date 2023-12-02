#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char *remove_prefix(char *string);

// typedef struct {
//   char *string;
//   int number;
// } lookup_table;

// lookup_table number_table[] = {{"one", 1},   {"two", 2},   {"three", 3},
//                                {"four", 4},  {"five", 5},  {"six", 6},
//                                {"seven", 7}, {"eight", 8}, {"nine", 9}};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    puts("File not passed as argument to executable");
  }

  FILE *file = fopen(argv[1], "r");

  if (file == NULL) {
    puts("File cannot be opened");
    return 0;
  }

  char line[200];

  while (fgets(line, sizeof(line), file)) {
    char *actual_input = remove_prefix(line);

    printf("%s", actual_input);
  }

  fclose(file);
  return 0;
}

char *remove_prefix(char *string) {
  char *colon_position = strstr(string, ":");

  return &colon_position[2];
}
