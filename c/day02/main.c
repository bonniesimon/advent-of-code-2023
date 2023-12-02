#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char *remove_prefix(char *string);
int check_valid_balls(char *game_string);

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

  char *next_game = NULL;

  while (fgets(line, sizeof(line), file)) {
    char *actual_input = remove_prefix(line);
    printf("LINE: %s", line);

    char *game = strtok(actual_input, ";");
    while (NULL != game) {
      int is_valid_game = check_valid_balls(*game);

      printf("is valid game: %d\n", is_valid_game);

      printf("game: %s\n", game);
      game = strtok(NULL, ";");
    }
  }

  fclose(file);
  return 0;
}

char *remove_prefix(char *string) {
  char *colon_position = strstr(string, ":");

  return &colon_position[2];
}

int check_valid_balls(char *game_string) { return 0; }
