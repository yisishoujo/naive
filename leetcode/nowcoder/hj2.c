#include <stdio.h>

int main() {
  char a[1001], b;
  for(int i = 0; i < 1001; i++) a[i] = 0;
  scanf("%[^\n]", a);
  scanf("\n%c", &b);
  if(b >= 'A' && b <= 'Z')
    b = b - 'A' + 'a';
  printf("%c\n", b);
  
  char *c = a;
  int count = 0;
  int valid = 1;
  while (*c) {
    // valid check
    //if((*c >= 'A' && *c <= 'Z') || (*c >= 'a' && *c <= 'z') || (*c == ' '))
    if((*c == b) || (*c == b + 'A' - 'a'))
      count++;
    c++;
  }
  printf("%d", count);
  return 0;
}
