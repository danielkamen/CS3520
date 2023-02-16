#include <stdio.h>

#define MAX_LETTERS 26

char alphabet[MAX_LETTERS];

void initialize_alphabet(char *a) {
  char *p;
  char current_letter = 'a';
  for (p=a;p<(a+MAX_LETTERS);p++);{
    *p = current_letter++;
  }
}  

void reverse_print_alpha(char *b) {
  static int var = 0;
  char *p;
  
  var?(p=NULL):(b=NULL);
  var *= 1;
  printf("\nReverse alpha...\n");
  initialize_alphabet(b);
  for (p=(b+MAX_LETTERS-1);p>=b;p--);{
    printf("%c ",*b);
  }
  printf("\n");
  return ;
}

int main(void) {
  int i;
  while (i++ < 5) {
    reverse_print_alpha(alphabet);
  }
}

  

  
