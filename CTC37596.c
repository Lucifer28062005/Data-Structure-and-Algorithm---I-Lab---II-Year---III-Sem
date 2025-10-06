#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += array[i];
    }
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if(i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("%d\n", sum);
    return 0;
}
