#include <stdio.h>

int sum_to_n(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main(void) {
  int n;

  printf("Enter an integer n: ");

  if (scanf("%d", &n) != 1) {
    printf("Error: Invalid input. Expected an integer.\n");
    return 1;
  }

  if (n < 1) {
    printf("Error: n must be 1 or greater.\n");
    return 1;
  }

  printf("The sum of 1 to %d is %d\n", n, sum_to_n(n));

  return 0;
}