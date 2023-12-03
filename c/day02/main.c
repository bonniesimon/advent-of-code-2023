#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_prefix(char *string) {
  char *colon_position = strstr(string, ":");

  return colon_position + 2;
}

void get_balls_in_reveal(char *game_string, char balls[][10],
                         int *number_of_balls) {
  char delimiters[] = ",";
  char *save_pointer;
  char *set = strtok_r(game_string, delimiters, &save_pointer);
  *number_of_balls = 0;

  while (NULL != set) {
    while (isspace((unsigned char)*set)) set++;

    strcpy(balls[*number_of_balls], set);
    (*number_of_balls)++;

    set = strtok_r(NULL, delimiters, &save_pointer);
  }
}

int is_valid_sets_in_game(char balls[][10], int number_of_balls) {
  for (int i = 0; i < number_of_balls; i++) {
    char *number = strtok(balls[i], " ");
    char *color = strtok(NULL, "");

    if (!strcmp(color, "red") && atoi(number) > 12) {
      printf("Invalid color: %s - Amount: %d\n", color, atoi(number));
      return 0;
    } else if (!strcmp(color, "green") && atoi(number) > 13) {
      printf("Invalid color: %s - Amount: %d\n", color, atoi(number));
      return 0;
    } else if (!strcmp(color, "blue") && atoi(number) > 14) {
      printf("Invalid color: %s - Amount: %d\n", color, atoi(number));
      return 0;
    }
  }

  return 1;
}

int get_game_number(char *line) {
  char *line_copy;
  line_copy = (char *)malloc(strlen(line) * sizeof(char) + 1);
  strcpy(line_copy, line);

  char *game_text = strtok(line_copy, " ");
  char *game_number_text = strtok(NULL, ":");

  int game_number = atoi(game_number_text);

  free(line_copy);

  return game_number;
}

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

  int valid_lines[101] = {0};
  int valid_lines_index = 0;

  char *line_copy;
  while (fgets(line, sizeof(line), file)) {
    printf("=========================\n%s", line);
    line_copy = (char *)malloc(strlen(line) * sizeof(char));
    strcpy(line_copy, line);

    char *actual_input = remove_prefix(line);

    int is_line_valid = 1;

    char *reveal_save_pointer;
    char *reveal = strtok_r(actual_input, ";", &reveal_save_pointer);
    while (NULL != reveal) {
      while (isspace((unsigned char)*reveal)) reveal++;

      char balls[30][10];
      int number_of_balls;
      char *game_string_copy;

      game_string_copy = (char *)malloc(strlen(reveal) * sizeof(char));
      strcpy(game_string_copy, reveal);

      get_balls_in_reveal(game_string_copy, balls, &number_of_balls);

      if (0 == is_valid_sets_in_game(balls, number_of_balls)) {
        is_line_valid = 0;
        break;
      }

      reveal = strtok_r(NULL, ";", &reveal_save_pointer);
      free(game_string_copy);
    }

    printf("is_valid: %d\n", is_line_valid);

    if (1 == is_line_valid) {
      valid_lines[valid_lines_index++] = get_game_number(line_copy);
    }
    free(line_copy);
  }

  int sum = 0;
  printf("[ ");
  for (int i = 0; i < valid_lines_index; i++) {
    printf("%d  ", valid_lines[i]);
    sum += valid_lines[i];
  }
  printf("]\n");

  printf("SUM = %d\n", sum);

  fclose(file);
  return 0;
}
