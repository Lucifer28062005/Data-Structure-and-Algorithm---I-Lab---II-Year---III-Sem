#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    // Read the N integers (data of nodes), but we don't need them for loop detection
    for(int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
    }
    
    int X;
    scanf("%d", &X);
    
    if(X == 0) {
        printf("False\n");
    } else {
        printf("True\n");
    }
    
    return 0;
}
