#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    int arr[M][N];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    // Print original matrix
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d", arr[i][j]);
            if(j < N) printf(" ");
        }
        printf("\n");
    }
    // Print transpose
    for(int j = 0; j < N; j++) {
        for(int i = 0; i < M; i++) {
            printf("%d", arr[i][j]);
            if(i < M) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
