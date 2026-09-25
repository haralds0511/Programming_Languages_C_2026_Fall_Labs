#include <stdio.h>

long long factorial(int n) {
  long long result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main(void) {
  int n;

  printf("Enter an integer n: ");
  if (scanf("%d", &n) != 1) {
    printf("Error: Invalid input. Expected an integer.\n");
    return 1;
  }

  if (n < 0) {
    printf("Error: Factorial is not defined for negative numbers.\n");
    return 1;
  }

  printf("%d! = %lld\n", n, factorial(n));

  return 0;
}