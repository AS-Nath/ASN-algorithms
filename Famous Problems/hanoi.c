#include <stdio.h>

void hanoi(int n, char* start, char* aux, char* target) {
  if (n == 1) {
    printf("Move %s to %s.\n", start, target);
    return;
  }
  hanoi(n-1, start, target, aux); 
  hanoi(1, start, aux, target); 
  hanoi(n-1, aux, start, target); 
  return; 
}

int main(void) {
  int n;
  scanf("%d", &n);
  char* start = "START";
  char* aux = "AUX";
  char* target = "TARGET";
  hanoi(n, start, aux, target); 
  return 0;
}
