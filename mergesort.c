#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int* sort(int* arr, int l);
int* merge(int* arr1, int l1, int* arr2, int l2);

int main(void) {
    int n;
    scanf("%d", &n); 
    int* arr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    sort(arr, n); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* sort (int* arr, int l) {
    if (l == 1) {
        return arr;
    }
    int mid = (int)(l / 2);
    int* left = arr;
    int* right = arr + mid;
    int l1 = mid;
    int l2 = l - mid; 
    left = sort(left, l1); 
    right = sort(right, l2);
    arr = merge(left, l1, right, l2); 
    return arr;
}

int* merge(int* arr1, int l1, int* arr2, int l2) {
    int* r_arr = (int *)calloc(l1 + l2, sizeof(int)); 
    int i1 = 0; int i2 = 0;
    int i = 0;
    while (i1 < l1 && i2 < l2) {
        if (arr1[i1] < arr2[i2]) {
            r_arr[i] = arr1[i1];
            i1 += 1;
        }
        else {
            r_arr[i] = arr2[i2];
            i2 += 1;
        }        
        i += 1;
    }
    while (i1 < l1) {
        r_arr[i] = arr1[i1];
        i1 += 1;
        i += 1;
    }
    while (i2 < l2) {
        r_arr[i] = arr1[i2];
        i2 += 1;
        i += 1;
    }
    return r_arr; 
}