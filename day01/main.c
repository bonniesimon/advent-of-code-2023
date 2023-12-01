#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
  char question[] = "a1b2c3d4e5f";
  char *digits = (char *) malloc(sizeof(char) * sizeof(question));
  char *pos_digits = digits;
  char *first, *last;

  first = digits;
  last = digits;

  bool atleast_one = false;

  printf("%c \n", *digits);
  while( *digits != '\0') {
    if (*digits < '0' || *digits > '9') continue;

    printf("%c \n", *digits);

    if (!atleast_one) {
      first = digits;
      last = digits;
      printf("%s", first);
      atleast_one = true;
      digits++;
      break;
    }

    last = digits;

    digits++;
  }

  printf("%s", last);
  /*
  for(size_t i = 0; question[i] != '\0'; i++) {
    if(question[i] >= '0' && question[i] <= '9'){
      *pos_digits = question[i];
      pos_digits++;
    }
  }

  for (size_t i = 0; digits[i] != '\0'; i++) {
    printf("%s\n", digits[i]);
  }
  */


  free(digits);
  return 0;
}
