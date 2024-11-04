#include <stdio.h>

int sort_b(int* a, int* b, int len) {
  int count = 1;
  b[0] = a[0];
  for(int i = 1; i < len; i++) {
    for(int j = 0; j < count; j++) {
      if((b[j] < a[i]) && (j < count - 1))
          continue;
      if(b[j] == a[i])
        break;
      if(b[j] > a[i]) {
        for(int k = count; k > j; k--) {
          b[k] = b[k-1];
        }
        b[j] = a[i];
        count++;
        break;
      }
      if(j == count - 1) {
        b[count] = a[i];
        count++;
      }
    }
  }
  return count;
}

int main() {
  int N;
  int a[1001], b[1001];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", a+i);
  }
  int no_dup = sort_b(a, b, N);
  for(int i = 0; i < no_dup; i++)
    printf("%d\n", b[i]);
}
