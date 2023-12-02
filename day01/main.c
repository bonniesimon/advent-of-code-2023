/*

PART 1

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct stack{
  int max;
  int top;
  int *items;
} Stack;

Stack *init_stack(int len);
void push(int value, Stack *s);
void print_stack(Stack *s);
int pop(Stack *s);
int calculate_magic_number(char *word, size_t length);

int main() {
  FILE *file = fopen("numberset.txt", "r");

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

Stack *init_stack(int len) {
  Stack *s = (Stack *) malloc(sizeof(Stack));
  (*s).max = len;
  (*s).top = -1;
  (*s).items = (int *) malloc(sizeof(int));

  return s;
}

void push(int value, Stack *s) {
  if (s->top == s->max - 1) {
    printf("Stackoverflow");
    return;
  }

  s->top++;
  s->items[s->top] = value;
}

void print_stack(Stack *s) {
  if (s->top == -1) {
    printf("Stack empty\n");
    return;
  }

  for (int i = 0; i <= s->top; i++) {
    printf("%d ---", s->items[i]);
  }
}

int pop(Stack *s) {
  if (s->top == -1) {
    return -1;
  }

  int value = s->items[s->top];
  s->top--;

  return value;
}

int calculate_magic_number(char *word, size_t length) {
  Stack *nums = init_stack(length);

  for (size_t i = 0; i < length; i++) {
    if (word[i] < '0' || word[i] > '9') continue;

    push(word[i] - '0', nums);
  }


  int last = pop(nums);
  int first = pop(nums);

  if (first == -1) {
    first = last;
  }

  int next_number = pop(nums);

  while(next_number != -1) {
    first = next_number;

    next_number = pop(nums);
  }

  free(nums);

  return first * 10 + last;
}
